keys = "ZWXUGHSFOI"

data = {"Z": ("ZERO", 0),
        "W": ("TWO", 2),
        "X" : ("SIX", 6),
        "U" : ("FOUR", 4),
        "G": ("EIGHT", 8),
        "H" : ("THREE", 3),
        "S" : ("SEVEN", 7),
        "F" : ("FIVE", 5),
        "O" : ("ONE", 1),
        "I" : ("NINE", 9)
        }

alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
def to_freq_table(word):
    d = {a : 0 for a in alph}
    for w in word:
        d[w] += 1
    return d

def solve(word):
    ft = to_freq_table(word)
    solution = []
    for key in keys:
        verbose, num = data[key]
        occs = ft[key]
        solution += [num]*occs
        for w in verbose:
            ft[w] -= occs
    for key in ft:
        assert ft[key] == 0
    return ''.join(str(x) for x in sorted(solution))


n = int(input())
for case in range(n):
    word = input()
    print("Case #{}: {}".format(case+1, solve(word)))
