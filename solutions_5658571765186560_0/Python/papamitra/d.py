import sys

def solve(l):
    x,r,c = [int(i) for i in l.split(' ')]
    if x == 1:
        return True
    if x == 2:
        return ((r*c) % 2) == 0
    if x == 3:
        return ((r%2==0) and (c%3==0)) or ((r%3==0) and (c%2==0)) or ((r==3) and (c==3))

    # x==4
    return ((r==4) and (c==4)) or ((r==3) and (c==4)) or ((r==4) and (c==3))

def main():
    sys.stdin.readline()
    for i,l in enumerate(sys.stdin.readlines(),1):
        r = solve(l)
        print("Case #{0}: {1}".format(i, "GABRIEL" if r else "RICHARD"))

if __name__ == '__main__':
    main()
