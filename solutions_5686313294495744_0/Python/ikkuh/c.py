T = int(input())

for i in range(T):
    n = int(input())
    words = [raw_input().split() for j in range(n)]

    possible_cheats = []
    for j, word in enumerate(words):
        possible_cheats.append(sum(word[0] == w[0] for w in words) > 1 and sum(word[1] == w[1] for w in words) > 1)

    result = 0
    print("Case #%d: %d" % (i+1, possible_cheats.count(True)))
