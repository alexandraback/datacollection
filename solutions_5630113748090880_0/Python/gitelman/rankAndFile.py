
from collections import Counter






def main():
    T = int(raw_input())
    for i in range(1, T+1):
        N = int(raw_input())
        concatList = []
        for j in range(2*N-1):
            concatList.extend(raw_input().split())
        concatCounter = Counter(concatList)
        ans = []
        for height in concatCounter:
            if concatCounter[height]%2 == 1:
                ans.append(height)
        print "Case #{}: {}".format(i, " ".join(sorted(ans, key = lambda x : int(x))))


if __name__ == "__main__":
    main()


