from array import *
import sys

def main():
    MAX_TIME = 1005
    t = int(raw_input())

    for caso in range(1, t + 1):
        d = int(raw_input())
        input = raw_input()
        v = []
        best = MAX_TIME

        for x in input.split():
            v.append(int(x))

        for i in range (1, MAX_TIME):
            aux = 0
            for j in range(0, d):
                if (v[j] > i):
                    aux = aux - 1 + (v[j] + i - 1) // i
            best = min(best, i + aux)
        print("Case #%d: %d" % (caso, best))


if __name__ == '__main__':
   main()
