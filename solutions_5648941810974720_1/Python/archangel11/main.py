filename = "a.in"
outfilename = "output.txt"

from collections import defaultdict

def solve(f):
    s = f.readline().strip()
    fmap = defaultdict(lambda:0)
    for c in s:
        fmap[c] += 1

    digits = ['ZERO', 'ONE', 'TWO', 'THREE', 'FOUR', 'FIVE', 'SIX',
              'SEVEN', 'EIGHT', 'NINE']

    ans = []

    while sum(fmap.values()) > 0:
        if fmap['Z'] > 0:
            for char in digits[0]:
                fmap[char] -= 1
            ans.append(0)
        elif fmap['W'] > 0:
            for char in digits[2]:
                fmap[char] -= 1
            ans.append(2)
        elif fmap['U'] > 0:
            for char in digits[4]:
                fmap[char] -= 1
            ans.append(4)
        elif fmap['X'] > 0:
            for char in digits[6]:
                fmap[char] -= 1
            ans.append(6)
        elif fmap['G'] > 0:
            for char in digits[8]:
                fmap[char] -= 1
            ans.append(8)
        elif fmap['O'] > 0:
            for char in digits[1]:
                fmap[char] -= 1
            ans.append(1)
        elif fmap['H'] > 0:
            for char in digits[3]:
                fmap[char] -= 1
            ans.append(3)
        elif fmap['F'] > 0:
            for char in digits[5]:
                fmap[char] -= 1
            ans.append(5)
        elif fmap['S'] > 0:
            for char in digits[7]:
                fmap[char] -= 1
            ans.append(7)
        else:
            for char in digits[9]:
                fmap[char] -= 1
            ans.append(9)


    return "".join(map(str, sorted(ans)))

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
