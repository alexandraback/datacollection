__author__ = 'Andrey'
fin = open("A-small-attempt0.in", "r")
fout = open("output.txt", "w")
t = int(fin.readline().rstrip())
for i in range(t):
    s = fin.readline().rstrip()
    cnt = dict()
    for char in "ABCDEFGHIJKLMNOPQRSTUVWXYZ":
        cnt[char] = 0
    for char in s:
        cnt[char] += 1
    # ZERO
    # ONE
    # TWO
    # THREE
    # FOUR
    # FIVE
    # SIX
    # SEVEN
    # EIGHT
    # NINE
    #a0, a1, a2, a3, a4, a5, a6, a7, a8, a9 = 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    a0 = cnt["Z"]
    a4 = cnt["U"]
    a3 = cnt["R"] - a0 - a4
    a6 = cnt["X"]
    a8 = cnt["H"] - a3
    a5 = cnt["F"] - a4
    a2 = cnt["W"]
    a1 = cnt["O"] - a0 - a2 - a4
    a7 = cnt["V"] - a5
    a9 = cnt["I"] - a5 - a6 - a8
    ls = [a0, a1, a2, a3, a4, a5, a6, a7, a8, a9]
    fout.write("Case #" + str(i + 1) + ": ")
    for i in range(10):
        fout.write(str(i) * ls[i])
    fout.write("\n")