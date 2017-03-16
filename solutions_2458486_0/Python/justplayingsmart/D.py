##input = open('D-sample-input.txt', 'r')
##output = open('D-sample-output.txt', 'w')

input = open('D-small-attempt1.in', 'r')
output = open('D-small.out', 'w')

##input = open('D-large.in', 'r')
##output = open('D-large.out', 'w')
hash = []

def doable(keys, chests, unopened):
##def doable(keys, chests, unopened, reflexives):
    keys_needed = []
    total_keys = keys[:]
    reflexives = []
    for chest in unopened:
        keys_needed.append(chests[chest][0])
        if chests[chest][1] > 0:
            total_keys.extend(chests[chest][2:])
            if chests[chest][0] in chests[chest][2:]:
                reflexives.append(chests[chest][0])   
    for key in set(keys_needed):
        if key in reflexives:
            if total_keys.count(key) == 1:
                return False
    return True

def func(N, keys, chests, opened, unopened, key_dict):
##def func(N, keys, chests, opened, unopened, key_dict, reflexives):
##    print 'opened =', opened
    if len(unopened) == 0:
        return opened
    if tuple(sorted(opened)) in hash:
        return False
    if not doable(keys, chests, unopened):
##    if not doable(keys, chests, unopened, reflexives):
        hash.append(tuple(sorted(opened)))
##        print 'not doable'
        return False
    openable_chests = []
    for key in set(keys):
        if not key_dict.has_key(key):
            continue
        for chest in key_dict[key]:
            if chest in unopened:
                openable_chests.append(chest)
    openable_chests.sort()
    for chest in openable_chests:
        opened.append(chest)
        unopened.remove(chest)
        key_needed = chests[chest][0]
        keys.remove(key_needed)
        new_keys = []
        if chests[chest][1] > 0:
##            print 'chest =', chest, 'num keys in chest =', chests[chest][1]
##            print 'chests chest', chests[chest][2:]
            new_keys = chests[chest][2:]
        keys.extend(new_keys)
        if func(N, keys, chests, opened, unopened, key_dict):
##        if func(N, keys, chests, opened, unopened, key_dict, reflexives):
            return opened        
        opened.pop(-1)
        unopened.append(chest)
        keys.append(key_needed)
        for key in new_keys:
            keys.remove(key)
##    print 'returning False'
    hash.append(tuple(sorted(opened)))
    return False
    
    


def solve(K, N, keys, chests):
##    print 'K =', K, 'N=', N, 'start keys =', keys
##    for chest in chests:
##        print chest
    global hash
    hash = []
    opened = []
    unopened = range(N)
    key_dict = {}
    total_keys = keys[:]
    reflexives = []
    for i in range(N):
        if chests[i][1] > 0:
            total_keys.extend(chests[i][2:])
            if chests[i][0] in chests[i][2:]:
                reflexives.append(chests[i][0])
        if key_dict.has_key(chests[i][0]):
            key_dict[chests[i][0]].append(i)
        else:
            key_dict[chests[i][0]] = [i]
##    print 'total keys', total_keys
##    for k, v in key_dict.items():
##        print k, v
    for key, chests_needing_key in key_dict.items():
##        print 'key =', key
##        print 'chests needing key =', len(chests_needing_key)
##        print 'total keys.count =', total_keys.count(key)
        if len(chests_needing_key) > total_keys.count(key):
            return "IMPOSSIBLE"
##    for k, v in key_dict.items():
##        print 'key =', k, 'chests =', v
##    answer = func(N, keys, chests, opened, unopened, key_dict, reflexives)
    answer = func(N, keys, chests, opened, unopened, key_dict)
    if answer:
        return " ".join([str(x+1) for x in answer])
    return "IMPOSSIBLE"
    
    

def main():
    num_cases = int(input.readline().strip())
    for case in range(1, num_cases+1):
        K, N = [int(x) for x in input.readline().split()]
        keys = [int(x) for x in input.readline().split()]
        chests = []
        for i in range(N):
            chests.append([int(x) for x in input.readline().split()])
##        if case == 12:
        solution = solve(K, N, keys, chests)
        solution_string = "Case #%d: %s" %(case, solution)
        output.write(solution_string + "\n")
        print solution_string
        

main()
input.close()
output.close()
    
