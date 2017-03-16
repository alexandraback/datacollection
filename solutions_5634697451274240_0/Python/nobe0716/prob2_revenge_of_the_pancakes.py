f_in = open('1.in')
f_out = open("1.out", "w")

def flip(pancake):
    for i in range(len(pancake)):
        pancake[i] = '-' if pancake[i] == '+' else '+'
    return pancake[::-1]


def solve(cake):
    i = len(cake) - 1
    while i >= 0 and cake[i] == '+':
        i -= 1
    if i < 0:
        return 0
    cake = cake[:i + 1]

    if '+' not in cake: # just flip entire
        return 1

    l = len(cake)
    if cake[0] == '+':
        i = 0
        while i < l and cake[i] == '+':
            cake[i] = '-'
            i += 1
        return 1 + solve(cake)
    elif cake[0] == '-':
        i = 0
        while i < l and cake[i] == '-':
            i += 1
        return 1 + solve(flip(cake[i:]))

    return 1

for t in range(1, int(f_in.readline()) + 1):
    pancake = list(f_in.readline().strip())
    r = solve(pancake)
    print("Case #%d: %d" % (t, r))
    f_out.write("Case #%d: %d\n" % (t, r))
f_out.close()

