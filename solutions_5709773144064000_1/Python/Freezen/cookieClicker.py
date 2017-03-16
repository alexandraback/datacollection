import sys
import math

def main():
    T = int(sys.stdin.readline())
    case = 1
    while T > 0:
        C_s, F_s, X_s = sys.stdin.readline().split()
        C = float(C_s)
        F = float(F_s)
        X = float(X_s)
        k = int(math.ceil(X / C - 2.0 / F - 1))
        result = 0
        if k > 0:
            for i in range(k):
                result += C / (2.0 + i * F)
            result += X / (2.0 + k * F)
        else:
            result += X / 2.0
        print 'Case #'+str(case)+': '+'%.7f'%result
        T -= 1
        case += 1

if __name__ == '__main__':
    main()
