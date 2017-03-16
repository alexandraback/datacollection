
from pprint import pprint 
import os
import pickle
import sys

init_state = [(1,(0,0),'')] # (length, coordinate, moves)
has_state = []

MOVES = {
        'w': (-1, 0),
        'e': (1,0),
        'n': (0,1),
        's': (0,-1)
        }
def coor_mul(a, n):
    return (a[0]*n, a[1]*n)

def coor_add(a, b):
    return (a[0]+b[0], a[1]+b[1])

def go_per_state(start_state):
    length = start_state[0]
    start = start_state[1]
    path = start_state[2]
    finish_state = []
    global has_state


    for direction, move_coor in MOVES.items():
        each_move = coor_mul(move_coor, length)
        end_coor = coor_add(start, each_move)
        if (end_coor in has_state) or (abs(end_coor[0]) > 100) or (abs(end_coor[1]) > 100):
            continue
        result = (length+1, end_coor, path+direction)
        finish_state.append(result)
        has_state.append(end_coor)

    return finish_state

def go(start_states):
    result = []
    for start_state in start_states:
        result += go_per_state(start_state)

    return result

def match(match_state, states):
    end_same = filter(lambda s: s[1] == match_state, states)
    return sorted(end_same, key=lambda s: len(s[2]))
    
def find_out(match_state, table):
    for states in table:
        result = match(match_state, states)
        if result:
            return result[0]
    print 'more than 500 steps'


if __name__ == '__main__':

    STEPS = 50

    if os.path.exists('table.pkl'):
        table = pickle.load(open('table.pkl'))
    else:
        table = [init_state]
        last_time = init_state
        for i in range(STEPS):
            thistime = go(last_time)
            table.append(thistime)
            last_time = thistime
            print len(has_state)
            print 'added to table'
            if len(has_state) > 40000:
                break
        pprint(has_state)
        pickle.dump(table, open('table.pkl','w'))


    lines = sys.stdin.readlines()
    lines = [line.strip() for line in lines][1:]

    for n,line in enumerate(lines):
        case = tuple(map(lambda x:int(x), line.split(" ")))
        print "Case #{0}: {1}".format(n+1, find_out(case, table)[2].upper())




