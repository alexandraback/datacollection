__author__ = 'OleksandrKonstantinov'

if __name__ == "__main__":
    with open("B-small-attempt0 (1).in", "r") as fRead, open("result.txt", "w") as fWrite:
        T = int(fRead.readline())
        for tc in range(1, T + 1):
            N = int(fRead.readline())
            all = {}
            for i in range (1, 2*N):
                for x in fRead.readline().split():
                    if int(x) in all:
                        all[int(x)] += 1
                    else:
                        all[int(x)] = 1

            ans = []
            for key in all:
                if all[key] % 2 != 0:
                    ans.append(key)
            ans.sort()
            fWrite.write("Case #" + str(tc) + ": " + ' '.join(str(x) for x in ans) + "\n")


