from itertools import product
import re

def solve(K, L, S, keyboards, target):
    """ solve the problem """

    #print(K, L, S, keyboards, target)
    for letter in target:
        if letter not in keyboards: return 0.0

    target_left = target[:]
    target_right = target[:]
    overlap = ''
    overlap_count = 0
    while True:
        if len(target_left) == 0: break
        target_left = target_left[1:]
        target_right = target_right[:-1]
        if target_left == target_right: 
            overlap = target_left[:]
            overlap_count = len(overlap)
            break
    #print(overlap)
    to_bring = int((S - L)/(L-overlap_count)) + 1
    #print(to_bring)

    #A = [[] for _ in range(S*K)]
    #for i in range(S):
    #    for j in range(S*K):
    #        A[j].append(keyboards[j%K])
   # 
   # All = [''.join(a) for a in A]
   # print(All)
    A = product(keyboards, repeat=S)
    found = 0
    count_A = 0
    for a in A: 
        count_A += 1
        #print(a)
        aa = ''.join(a)
        #cur_found = re.findall(target, aa)
        #print(aa, target, cur_found)
        cur_found = 0
        beg = 0
        while beg < len(aa):
            index = aa.find(target, beg)
            if index != -1:
                cur_found+= 1
                beg = index + 1
            else:
                break
        #print(aa, target, cur_found)
        found += cur_found

    ans = to_bring - 1.0*found/count_A
    #print(to_bring, found, count_A)

    return  ans


def parse():
    """ parse input """

    K, L, S = [int(i) for i in input().split()]
    keyboards = input()
    target = input()

    return K, L, S, keyboards, target


def main():
    
    T = int(input())

    # solve
    for t in range(1, T+1):
        params = parse()
        result = solve(*params)
        print('Case #%d: %s' % (t, result))


if __name__ == '__main__':

    main()
