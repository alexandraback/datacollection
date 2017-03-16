# -*- coding: utf-8 -*-
# convert an input file of problem B to LOLCODE-friendly format


def main():
    T = input()

    print T
    for i in range(T):
        N, M = (int(x) for x in raw_input().split())
        print '%d\n%d' % (N, M)

        for j in range(N):
            print '\n'.join(raw_input().split())

if __name__ == '__main__':
    main()
