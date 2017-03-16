__author__ = 'OleksandrKonstantinov'

if __name__ == "__main__":
    with open("A-small-attempt0 (1).in", "r") as fRead, open("result.txt", "w") as fWrite:
        T = int(fRead.readline())
        for tc in range(1, T + 1):
            s = fRead.readline()
            ans = ""
            ans += s[0]
            for i in range(1, len(s)):
                if s[i] >= ans[0]:
                    ans = s[i] + ans
                else:
                    ans += s[i]

            fWrite.write("Case #" + str(tc) + ": " + ans)

