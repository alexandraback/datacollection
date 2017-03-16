filename = "a.in"
outfilename = "output.txt"

def solve(f):
    output = 0
    s = f.readline().strip()
    ans = s[0]
    for c in s[1:]:
        if c >= ans[0]:
            ans = c + ans
        else:
            ans += c

    return ans

def out(s, o):
    print s
    o.write("{}\n".format(s))

def main():
    f = open(filename)
    o = open(outfilename, 'w+')
    T = int(f.readline())
    t = 1
    while t <= T:
        output = solve(f)
        out("Case #{}: {}".format(t, output), o)
        t+=1

if __name__ == "__main__":
    main()
