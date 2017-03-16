#!/usr/bin/env python3
from collections import *

def main(*args):
    c, j = args
    ca, ja = '', ''
    bigger = None
    for cx, jx in zip(c, j):
        if cx == jx:
            if cx == '?':
                if bigger == 'c':
                    ca += '0'
                    ja += '9'
                elif bigger == 'j':
                    ca += '9'
                    ja += '0'
                else:
                    ca += '0'
                    ja += '0'
            else:
                ca += cx
                ja += jx
        else:
            if not bigger:
                if cx == '?':
                    ca += jx
                    ja += jx
                elif jx == '?':
                    ca += cx
                    ja += cx
                elif int(cx) > int(jx):
                    bigger = 'c'
                elif int(cx) < int(jx):
                    bigger = 'j'
            if bigger:
                if bigger == 'c':
                    if cx == '?':
                        ca += '0'
                    else:
                        ca += cx
                    if jx == '?':
                        ja += '9'
                    else:
                        ja += jx
                elif bigger == 'j':
                    if cx == '?':
                        ca += '9'
                    else:
                        ca += cx
                    if jx == '?':
                        ja += '0'
                    else:
                        ja += jx
                else:
                    if cx == '?':
                        ca += jx
                    else:
                        ca += cx
                    if jx == '?':
                        ja += cx
                    else:
                        ja += jx
    return ' '.join((ca, ja))

if __name__ == '__main__':
    for i in range(int(input())):
        print("Case #{}: {}".format(i + 1, main(*input().split())))
