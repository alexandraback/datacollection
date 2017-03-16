def options(t):
    if t == 0:
        return (0,0)
    elif t == 1:
        return (1, 1)
    elif t == 2:
        return (1, 2)
    elif t % 3 == 0:
        return (t / 3, t / 3 + 1)
    elif t % 3 == 1:
        return (t / 3 + 1, t / 3 + 1)
    else: # t % 3 == 2
        return (t / 3 + 1, t / 3 + 2)

def solve(surprises, totals, p):
    result = 0
    remaining = surprises
    for t in totals:
        max_no, max_with = options(t)
        if max_no >= p:
            result += 1
            continue
        if max_with >= p and remaining >= 1:
            remaining -= 1
            result += 1
    return result

def main():
    import sys
    data = open(sys.argv[1]+'.in').readlines()
    out = open(sys.argv[1]+'.out','w')
    for i, line in enumerate(data[1:]):
        entries = map(int, line.strip().split())
        n, s, p, scores = entries[0], entries[1], entries[2], entries[3:]
        answer = solve(s, scores, p)
        response = "Case #%i: %s" % (i+1, answer)
        print response
        out.write(response+'\n')
    out.close()

if __name__ == "__main__":
    main()