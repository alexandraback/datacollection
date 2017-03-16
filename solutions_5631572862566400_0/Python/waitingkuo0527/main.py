from itertools import permutations 
def solve(N, F):
    """ solve the problem """

    kids = [i for i in range(N)]
    for num in range(N, 1, -1):
        for p in permutations(kids, num):
            #print(p)
            found = True
            for i, kid in enumerate(p):
                if i == 0:
                    left = num-1
                    right = i+1
                elif i == num-1:
                    left = i-1
                    right = 0
                else:
                    left = i-1
                    right = i+1
                if F[kid] != p[left] and F[kid] != p[right]:
                    found = False
                    #print(i, kid)
                    break
            if found: return num

    return  1/0


def parse():
    """ parse input """

    N = int(input())
    F = [int(i)-1 for i in input().split()]

    return N, F


def main():
    
    T = int(input())

    # solve
    for t in range(1, T+1):
        params = parse()
        result = solve(*params)
        print('Case #%d: %s' % (t, result))


if __name__ == '__main__':

    main()
