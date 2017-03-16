import sys

def Ominous():
    T = int(sys.stdin.readline())
    for case in range(1,T+1):

        X, R, C = map(int, sys.stdin.readline().strip().split(' '))

        ans = True

        if X >= 7:
            ans = False
        elif X > R and X > C:
            ans = False
        elif R * C % X != 0:
            ans = False
        elif (X + 1) // 2 > min(R, C):
            ans = False
        elif X in (1, 2, 3):
            ans = True
        elif X == 4:
            ans = min(R, C) > 2
        elif X == 5:
            ans = not(min(R, C) == 3 and max(R, C) == 5)
        elif X == 6:
            ans = min(R, C) > 3

        print 'Case #%d:' % (case), 'GABRIEL' if ans else 'RICHARD'
    
if __name__ == '__main__':
    Ominous()
