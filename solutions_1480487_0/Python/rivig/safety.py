import sys, string

def safety(n, ss):
    tot = float(sum(ss))
    ans = []
    for s in ss:
        ss_desc = sorted(ss, None, None, True)
        nn = n
        p = 2. / nn - s / tot
        bounty = tot
        while nn > 2 and ss_desc[0] > s:
            if s + p * tot >= ss_desc[0]: break
            nn -= 1
            bounty -= ss_desc.pop(0)
            p = bounty/(tot*nn) + 1. / nn - s / tot
        ans.append(100. * max(0, p))
    return " ".join(map(str, ans))

def main(args):
    f = file(args[1])
    ncases = int(f.readline())
    for i in range(ncases):
        line = f.readline().rstrip()
        nums = map(int, line.split(" "))
        ans = safety(nums[0], nums[1:])
        sys.stdout.write("Case #%d: %s\n" % (i+1, ans))

if __name__ == "__main__":
    main(sys.argv)