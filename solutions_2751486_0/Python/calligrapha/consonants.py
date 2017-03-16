vowels = ['a', 'e', 'i', 'o', 'u']

def solve(line):
    line = line.split()
    s = line[0]
    n = int(line[1])
    start = 0
    end = 0
    last = -1
    result = 0
    while start < len(s):
        if s[start] not in vowels:
            end = start + 1
            while end < len(s) and end - start != n:
                if s[end] not in vowels:
                    end += 1
                else:
                    break
            if end - start == n:
                before = start - last
                after = len(s) - end + 1
                print s[start:end], before, after
                result += before * after
                last = start
            if end < len(s) and (s[end] in vowels):
                start = end
            else:
                start += 1
        else:
            start += 1
    return result

f = open("in.txt", "r")
T = int(f.readline())
out = open("out.txt", "w")
for test in range(1, T+1):
    result = solve(f.readline().strip())
    out.write("Case #%s: %s\n" % (test, result))
out.close()
