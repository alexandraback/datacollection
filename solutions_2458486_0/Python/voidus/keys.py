#!/usr/bin/env python3
# -*- coding:utf-8 -*-
import sys
from collections import defaultdict, namedtuple

Chest = namedtuple('Chest', ('number', 'open_with', 'holds'))
        
class User(object):
    def __init__(self, keys, chests):
        self.keys = defaultdict(int)
        for key in keys:
            self.keys[key] += 1
        self.chests = chests
        self.path = []

    def can_open_chest(self, chest):
        return (chest.number not in self.path) and self.keys[chest.open_with] > 0
    
    def open_chest(self, chest):
        if self.can_open_chest(chest):
            self.keys[chest.open_with] -= 1
            for key in chest.holds:
                self.keys[key] += 1
            self.path.append(chest.number)

    def list_available_chests(self):
        return [chest for chest in self.chests if self.can_open_chest(chest)]
    
    def is_stuck(self):
        return len(self.list_available_chests()) == 0
    
    def can_move(self):
        return not self.is_stuck()
    
    def has_won(self):
        return len([chest for chest in self.chests if chest.number in self.path]) == len(self.chests)
    
    def fork(self):
        keys = []
        for key, value in self.keys.items():
            keys += [key]*value
        user = User(keys, [Chest(*chest) for chest in self.chests])
        user.path = list(self.path)
        return user
    
    def get_move(self):
        if self.is_stuck() and not self.has_won():
            return []
        else:
            available = self.list_available_chests()
            if len(available) == 1:
                return [(self, available[0])]
            else:
                users = [self] + [self.fork() for i in range(len(available)-1)]
                return zip(users, available)
            
    def get_path(self):
        return ' '.join('%d' % number for number in self.path)
    
    def __repr__(self):
        return 'User of path {0}'.format(self.get_path())


class Game(object):
    def __init__(self, keys, chest_data):
        self.keys = keys
        self.chests = [Chest(*chest_item) for chest_item in chest_data]
        self.users = [User(self.keys, self.chests)]
        
    def run(self):
#        import ipdb; ipdb.set_trace()
        i = 0
        while True:
            stop_game = all(user.is_stuck() for user in self.users)
            i += 1
            if stop_game:
                break
            else:
                self.fork_and_move()
            assert all(len(user.path) == i for user in self.users if user.can_move())
            #sys.stderr.write('i = {0}, len={1}'.format(i, len(self.users)))
            #sys.stderr.flush()
        has_won = False
        winners = []
        for user in self.users:
            if user.has_won():
                winners.append(user)
                has_won = True
        if has_won:
            path = self.get_winner_path(winners)
            return path
        else:
            return 'IMPOSSIBLE'
            
    def fork_and_move(self):
        moves = []
        for user in self.users:
            moves += user.get_move()
        users = []
        invariants = defaultdict(list)
        for user, chest in moves:
            invariants[tuple(set(user.path))+tuple(chest.holds)].append((user, chest))
        moves = []
        for movie_list in invariants.values():
            moves.append(min(movie_list, key=lambda item: min(item[0].path+[item[1].number])))
        for user, chest in moves:
            users.append(user)
            if chest is not None:
                user.open_chest(chest)
        paths = defaultdict(list)
        for user in users:
            paths[tuple(set(user.path))].append(user)
        users = []
        for userlist in paths.values():
            users.append(min(userlist, key=lambda user:user.path))
        self.users = users
    
    def get_winner_path(self, winners):
        winner = min(winners, key=lambda user:user.path)
        return winner.get_path()

def solve_case(starting_keys, chests):
    game = Game(starting_keys, chests)
    result = game.run()
    return result

def handle_line(source):
    line = next(source)
    return tuple(map(int, line.strip().split(' ')))

def handle_input(source):
    number, = handle_line(source)
    for index in range(number):
        chests = []
        keytypes_start_count, chest_number = handle_line(source) 
        starting_keys = handle_line(source)
        for j in range(chest_number):
            line = handle_line(source)
            chests.append((j+1, line[0], list(sorted(line[2:]))))
        result = solve_case(starting_keys, chests)
        print('Case #{0}: {1}'.format(index+1, result))

if __name__ == '__main__':
    handle_input(sys.stdin)
    #handle_input(open('input.txt', 'rt'))
    #handle_input(open('D-small-attempt1.in', 'rt'))