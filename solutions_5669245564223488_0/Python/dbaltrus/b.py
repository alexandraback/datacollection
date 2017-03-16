import sys

def factorial(a):
    f = 1
    for x in range(1, a + 1):
        f *= x
        f %= 1000000007
    return f

lines = sys.stdin.readlines()
T = int(lines[0])
for t in range(0, T):
    N = int(lines[t * 2 + 1])
    trains = lines[t * 2 + 2].split()
    whole = [0] * (ord('z') - ord('a') + 1)
    start = [[] for i in range(ord('z') - ord('a') + 1)]
    end = [[] for i in range(ord('z') - ord('a') + 1)]
    inside = [0] * (ord('z') - ord('a') + 1)
    for train in trains:
        start_chr = train[0]
        num_start = 1
        while num_start < len(train) and train[num_start] == start_chr:
            num_start += 1
        if num_start == len(train):
            whole[ord(start_chr) - ord('a')] += 1
        else:
            end_chr = train[-1]
            num_end = -1
            while train[num_end] == end_chr:
                num_end -= 1
            start[ord(start_chr) - ord('a')].append((ord(start_chr) - ord('a'), ord(end_chr) - ord('a')))
            end[ord(start_chr) - ord('a')].append((ord(start_chr) - ord('a'), ord(end_chr) - ord('a')))
            for c in list(set(train[num_start:(num_end + 1)])):
                inside[ord(c) - ord('a')] += 1
    for i in range(len(whole)):
        if (len(start[i]) + inside[i]) > 1 or (len(end[i]) + inside[i]) > 1:
            print('Case #{}: 0'.format(t + 1))
            break
    else:
        broken = False
        for i in range(len(start)):
            if len(start[i]) > 0:
                cart1 = start[i][0]
                while len(start[cart1[1]]) > 0 and cart1[1] != cart1[0]:
                    cart2 = start[cart1[1]][0]
                    start[i].pop()
                    if len(start[cart1[1]]) > 0:
                        start[cart1[1]].pop()
                    cart1 = (cart1[0], cart2[1])
                    start[i].append(cart1)
                if cart1[0] == cart1[1]:
                    print('Case #{}: 0'.format(t + 1))
                    broken = True
                    break
        if not broken:
            trains = 0
            permutations = 1
            for i in range(len(whole)):
                if whole[i] > 0:
                    permutations *= factorial(whole[i])
                    permutations %= 1000000007
                    trains += 1
            for i in range(len(start)):
                for cart in start[i]:
                    if whole[cart[0]] == 0 and whole[cart[1]] == 0:
                        trains += 1
                    if whole[cart[0]] > 0 and whole[cart[1]] > 0:
                        trains -= 1
            permutations *= factorial(trains)
            permutations %= 1000000007
            print('Case #{}: {}'.format(t + 1, permutations))

