S1 = "ejpmysljylckdkxveddknmcrejsicpdrysirbcpcypcrtcsradkhwyfrepkymveddknkmkrkcddekrkdeoyakwaejtysrreujdrlkgcjvzq"
S2 = "ourlanguageisimpossibletounderstandtherearetwentysixfactorialpossibilitiessoitisokayifyouwanttojustgiveupqz"
T = dict()
for i in range(len(S1)):
    if S1[i] in T:
        if S2[i] != T[S1[i]]:
            print("Diff letter", S1[i])
    else:
        T[S1[i]] = S2[i]
T[" "] = " "
# print(len(T))
# print(len(set(T.keys())))
# print(len(set(T.values())))
# print(T)
# for s in sorted(list(T.keys())):
#    print(s, T[s])

n = int(input())
for num in range(1, n + 1):
    S = input()
    Ans = ""
    for c in S:
        Ans += T[c]
    print("Case #" + str(num) + ":", Ans)


