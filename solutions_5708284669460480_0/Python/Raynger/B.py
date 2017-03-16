def find_max(S, target):
    i = 0
    j = len(target) - 1
    counter = 0 
    while i < j:
        if i == j:
            counter += 1
        else:
            break
    return counter, 1 + ((S - counter) // (len(target) - counter))

for c in range(int(input())):
    K, L, S = list(map(int, input().split()))
    keyboard = input()
    keys = dict()
    for i in keyboard:
        if i not in keys:
            keys[i] = 1
        else:
            keys[i] += 1
            
    #print(keys)
    flag = False
    target = input()
    stat = 1
    for letter in target:
        if letter not in keys:
            flag = True
            break
        else:
            stat *= (keys[letter] / K)
    reap, max_n = find_max(S, target)
    one = stat * (S - (L - 1))
    #print(one)
    
    new_t = target + target[len(target)-reap:]
    two = 1
    for letter in new_t:
        if letter not in keys:
            flag = True
            break
        else:
            two *= (keys[letter] / K) 
    duo = two * (S - (len(new_t) - 1))
    one -= duo
    #print(duo)
    #print(max_n)
    if flag:
        ex = 0.0
    else:
        ex = max(0.0, (max_n - (one * 1) - (duo * 2)))
    print("Case #{}: {}".format(c+1, ex))