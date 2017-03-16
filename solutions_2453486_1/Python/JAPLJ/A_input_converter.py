# -*- coding: utf-8 -*-
# convert an input file of problem A to LOLCODE-friendly format


def main():
    T = input()

    print T
    for i in range(T):
        for j in range(4):
            print '\n'.join(c for c in raw_input())
        try:
            raw_input()
        except:
            pass

if __name__ == '__main__':
    main()
