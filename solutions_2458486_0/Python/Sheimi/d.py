#!/usr/bin/env python
import sys


def print_result(case_no, msg):
    print "Case #%d: %s" % (case_no, msg)


def can_open(locks, keys, chests):
    open_list = []
    for key in keys:
        if key not in locks:
            continue
        for no in locks[key]:
            if no in chests:
                open_list.append((no, key))
    open_list.sort(lambda x, y: chests[y[0]]['ranking'] - chests[x[0]]['ranking'])
    if open_list and chests[open_list[0][0]]['ranking'] == 10000:
        return [open_list[0]]
    return open_list


def open_chests(chests, locks, keys, result_list):
    if len(chests) == 0:
        return True
    for no, key in can_open(locks, keys, chests):
        if no not in chests:
            continue
        result_list.append(no)
        new_keys = list(keys)
        new_keys.remove(key)
        new_keys.extend(chests[no]['inner_keys'])
        chest = chests.pop(no)
        result = open_chests(chests, locks, new_keys, result_list)
        if result:
            return True
        result_list.pop()
        chests[no] = chest
    return False

def run_case(case_no):
    K, N = raw_input().split()
    K, N = int(K), int(N)

    keys_now = raw_input().split()
    keys_now = [int(key) for key in keys_now]
    
    chests = {}
    locks = {}

    required_keys = {}
    for no in range(N):
        raw = raw_input().split()
        key_raw = int(raw[0])
        if key_raw in locks:
            locks[key_raw].append(no)
        else:
            locks[key_raw] = [no]

        if key_raw in required_keys:
            required_keys[key_raw] += 1
        else:
            required_keys[key_raw] = 1

        keys = [int(key) for key in raw[2:]]
        chests[no] = {
            'inner_keys': keys,
            'lock_key': key_raw,
        }

    all_keys = {}

    for key in keys_now:
        if key in all_keys:
            all_keys[key] += 1
        else:
            all_keys[key] = 1

    for _, value in chests.items():
        for key in value['inner_keys']:
            if key in all_keys:
                all_keys[key] += 1
            else:
                all_keys[key] = 1

    print >> sys.stderr, all_keys
    print >> sys.stderr, required_keys

    for key, num in required_keys.items():
        if key not in all_keys or all_keys[key] < num:
            print_result(case_no, 'IMPOSSIBLE')
            return

    del all_keys
    del required_keys

    usable_keys_set = set(locks.keys())
    for key in keys_now:
        if key not in usable_keys_set:
            keys_now.remove(key)

    for _, value in chests.items():
        for key in value['inner_keys']:
            if key not in usable_keys_set:
                value['inner_keys'].remove(key)

    for no, value in chests.items():
        if value['lock_key'] in value['inner_keys']:
            value['ranking'] = 10000
            continue
        value['ranking'] = len(value['inner_keys'])

    result_list = []
    result = open_chests(chests, locks, keys_now, result_list)
    if result:
        msg = " ".join((str(chest + 1) for chest in result_list))
        print_result(case_no, msg)
    else:
        print_result(case_no, 'IMPOSSIBLE')

if __name__ == '__main__':
    num = int(raw_input())
    for i in xrange(num):
        run_case(i + 1)
