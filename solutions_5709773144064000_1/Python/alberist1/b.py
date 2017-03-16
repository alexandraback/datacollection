#!/usr/bin/pypy

def solve():
    C, F, X = map(float,raw_input().split())
    build_time = 0
    speed = 2
    best_time = build_time+X/speed
    while build_time < best_time:
        build_time += C / speed
        speed += F
        best_time = min(best_time,build_time+X/speed)
    print "%.7f"%best_time

if __name__=="__main__":
    T = int(raw_input())
    for i in range(1,T+1):
        print "Case #%d:"%i,
        solve()
