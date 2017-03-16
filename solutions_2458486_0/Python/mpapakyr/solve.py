#! /usr/bin/python

import os, sys, math, re
import copy

    # print_state(keys, Ti, KiData)
    # _, keys, Ti = move(keys, Ti, KiData, 2)
    # _, keys, Ti = move(keys, Ti, KiData, 1)
    # _, keys, Ti = move(keys, Ti, KiData, 4)
    # _, keys, Ti = move(keys, Ti, KiData, 3)
    # print_state(keys, Ti, KiData)
    # if finished(Ti):
    #     sys.stdout.write('FINISHED !!!\n')


def finished(Ti):
    for lock in Ti.values():
        if lock <> -1:
            return False
    return True


def print_state(keys, Ti, KiData):
    sys.stdout.write('------state-----\n')
    for chest in Ti:
        needed_key = Ti[chest]
        sys.stdout.write('Chest %s\t[%s]\n' % (
            'unlocked' if Ti[chest]==-1 else 'lock(%s)' % needed_key,
            ','.join([str(x) for x in KiData[chest]])
            ))
    sys.stdout.write('\nKeys available: %s\n' % 
                     ' '.join([str(x) for x in keys]))
    sys.stdout.write('----------------\n')

def move(keys, Ti, KiData, chest):
    needed_key = Ti[chest]
    if needed_key in keys: # we have a key:
        Ti = copy.copy(Ti)
        Ti[chest] = -1
        keys = copy.copy(keys)
        keys.remove(needed_key)
        keys.extend(KiData[chest])
        return True, keys, Ti
    else:
        return False, keys, Ti

def solve(K, N, keys, Ti, Ki, KiData, moves, states):
    only_empty = True
    for chest in Ti:
        if Ti[chest] == -1: continue
        if not KiData[chest] == []:
            only_empty = False
            break

    for chest in Ti:
        skip = len(keys) == 1 and KiData[chest] == []
        if not Ti[chest] == -1 and (only_empty or not skip):
            #print '%s iterating on %s' % (moves, str(chest+1))
            ret = solve_aux(K, N, keys, Ti, Ki, KiData, moves, chest, states)
            if ret is not None:
                return ret

def solve_aux(K, N, keys, Ti, Ki, KiData, moves, next_chest, states):
    chest = next_chest
    moved, keys, Ti = move(keys, Ti, KiData, chest)
    if '%s' % Ti in states:
        return 
    finish = finished(Ti)
    if moved and finish:
        #print '%s _ finished with this move %s' % (moves, str(chest+1))
        moves = copy.copy(moves)
        moves.append(chest+1)
        #print '%s _ ret is : %s' % (moves, moves)
        return moves
    elif moved:
        #print '%s _ attempting move to %s' % (moves, str(chest+1))
        moves = copy.copy(moves)
        moves.append(chest+1)
        states.add('%s' % Ti)
        return solve(K, N, keys, Ti, Ki, KiData, moves, states)
    else:
        #print '%s _ failed move to %s' % (moves, str(chest+1))
        return None

T = int(sys.stdin.readline())

for i in range(0, T):
    Ti = {}
    Ki = {}
    KiData = {}
    line = sys.stdin.readline().split(' ')
    K = int(line[0])
    N = int(line[1])
    # K-size list:
    keys = [int(x) for x in sys.stdin.readline().split(' ')]
    for j in range(0, N):
        line = sys.stdin.readline().split(' ')
        Ti[j] = int(line[0])
        Ki[j] = int(line[1])
        KiData[j] = [int(x) for x in line[2:]]

    #print_state(keys, Ti, KiData)
    result = solve(K, N, keys, Ti, Ki, KiData, [], set())
    sys.stdout.write('Case #%s: %s\n' % (
            i+1, 
            'IMPOSSIBLE' if not result else ' '.join([str(x) for x in result])))

