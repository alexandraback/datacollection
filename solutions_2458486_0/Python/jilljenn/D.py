# coding=utf8
from itertools import permutations
from collections import Counter

chars = range(1, 21)
superpath = []

DEBUG = 0

def alltopsorts(current_path, k, pref=[]):
    global n, relations, chars, superpath
    if superpath:
        # print superpath
        return
    if len(pref) > len(current_path) and pref[:len(current_path)] != current_path:
        return
    
    if k == n:
        superpath.append(pref)
        return

    count = [ sum([1 for r in relations if r[1] == i]) for i in range(n)]
    D = [i for i,c in enumerate(count) if c == 0 and chars[i] not in pref]

    if len(D) > 0:
        for d in D:
            erased = [r for r in relations if r[0] == d]
            relations = [r for r in relations if r[0] != d]
            alltopsorts(current_path, k+1, pref + [chars[d]])
            relations += erased

def dfs(current_path, keys):
    global n, key_required, chest_containing_key, relations, superpath
    if DEBUG:
        print '=> Je suis actuellement dans', current_path
    accessibles = []
    if len(current_path) == n:
        return current_path
    relations = []
    if DEBUG >= 2:
        print 'Coffres contenant chaque cle', chest_containing_key
        print 'J\'ai besoin de', key_required
        print Counter([key_required[i] for i in range(1, N + 1) if i not in current_path])
    for i in range(1, N + 1):
        k = key_required[i] # Clé nécessaire pour ouvrir le coffre i
        if not keys[k] and k in chest_containing_key and len(chest_containing_key[k]) == 1 and key_required[chest_containing_key[k][0]] == k:
            # print u'Clé dans son propre coffre'
            return None
        if keys[k] + (len(chest_containing_key[k]) if k in chest_containing_key else 0) < len([key_required[c] for c in range(1, N + 1) if c not in current_path and key_required[c] == k]):
            #pass
            print 'La cle', i, 'est requise', Counter(key_required)[key_required[i]], 'fois mais n\'apparait que dans', chest_containing_key[key_required[i]]
            return None
        if i not in current_path and key_required[i] not in keys and key_required[i] in chest_containing_key and len(chest_containing_key[key_required[i]]) == 1:
            c = chest_containing_key[key_required[i]][0]
            if c != i:
                if i in current_path and c not in current_path:
                    return None
                # relations.append((c - 1, i - 1))
    if relations:
        print 'relations', relations
        superpath = []
        alltopsorts(current_path, 0)
        if not superpath:
            return None
    #print 'He!', superpath
    # S'il y a une issue, avancer
    for i in range(1, N + 1):
        if i not in current_path and keys[key_required[i]]:
            accessibles.append(i)
    if DEBUG >= 2:
        print current_path, keys, 'access', accessibles
    for chest in accessibles:
        keys[key_required[chest]] -= 1
        keys.update(keys_by_chest[chest])
        for k in keys_by_chest[chest]:
            chest_containing_key[k].remove(chest)
        tmp = dfs(current_path + [chest], keys)
        if tmp:
            #print 'stupeur'
            return tmp
        for k in keys_by_chest[chest]:
            chest_containing_key[k].append(chest)
        keys[key_required[chest]] += 1
        keys.subtract(keys_by_chest[chest])
        #break # FIXME

if __name__ == '__main__':
    T = int(raw_input())
    for t in range(T):
        keys_by_chest = {}
        chest_containing_key = {}
        K, N = map(int, raw_input().split())
        n = N
        keys_init = map(int, raw_input().split())
        available_keys = Counter(keys_init)
        key_required = [0] * (N + 1)
        for i in range(1, N + 1):
            l = map(int, raw_input().split())
            key_required[i] = l[0]
            keys_by_chest[i] = l[2:]
            for k in l[2:]:
                chest_containing_key.setdefault(k, []).append(i)
                available_keys[k] += 1
        required_keys = Counter(key_required[1:])
        available_keys.subtract(required_keys)
        if any(c < 0 for c in available_keys.values()):
            if DEBUG:
                print available_keys
            r = None
        else:
            if DEBUG:
                print available_keys 
            r = dfs([], Counter(keys_init))
        print 'Case #%d: %s' % (t + 1, ' '.join(map(str, r)) if r else 'IMPOSSIBLE')
