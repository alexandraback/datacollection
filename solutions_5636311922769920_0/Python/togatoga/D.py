
def solve():
    T = int(input())
    for case_id in range(T):
        K,C,S = map(int, input().split())
        cnt = 1
        ans = []
        for i in range(S):
            ans.append(cnt)
            cnt += 1
        print ("Case #%d: %s" % (case_id + 1, " ".join(map(str, ans))))
if __name__ == "__main__":
    solve()
