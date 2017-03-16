N = 2501

def main():
    t = int(raw_input())
    for i in xrange(1, t + 1):
        n = int(raw_input())
        occurences = []
        for j in range(N):
            occurences.append(0)
        for j in range(2 * n - 1):
            nums = [int(s) for s in raw_input().split(" ")]
            for x in nums:
                occurences[x] += 1
        missing = []
        for j in range(N):
            if occurences[j] % 2 != 0:
                missing.append(j)
        missingstr = ""
        for m in missing:
            missingstr += " %i" % m
        print("Case #%i:" %i + missingstr)

if __name__ == "__main__":
    main()
