import sys

def test():
    _, levels = sys.stdin.readline().strip().split()
    levels = map(int, levels)

    totalStanding = 0
    friends = 0
    for level, num in enumerate(levels):
        # How many more people we need to get these to stand
        deficiency = max(0, level - totalStanding)
        friends += deficiency
        totalStanding += num + deficiency
    return friends

def main(n):
    ''' Read and perform n test cases. '''
    for i in range(n):
        answer = test()
        print('Case #{}: {}'.format(i+1, answer))

if __name__ == '__main__':
    n = int(sys.stdin.readline())
    main(n)

