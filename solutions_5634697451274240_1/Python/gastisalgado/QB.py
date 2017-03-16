from base import cases

def solve(s):
    t = 0 if s[-1] == "+" else 1
    last=s[0]
    for x in s:
        if x != last:
            last=x
            t+=1
    return t

if __name__ == "__main__":
    cases(solve)
