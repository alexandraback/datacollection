def simplify(g):
    a, b = g
    curr_a = a
    curr_b = b
    while len(curr_a) > 1:
        if curr_a[:2] in ["ii", "jj", "kk"]:
            curr_a, curr_b = curr_a[2:], -curr_b
        elif curr_a[:2] in ["ij"]:
            curr_a, curr_b = "k" + curr_a[2:], curr_b
        elif curr_a[:2] in ["jk"]:
            curr_a, curr_b = "i" + curr_a[2:], curr_b
        elif curr_a[:2] in ["ki"]:
            curr_a, curr_b = "j" + curr_a[2:], curr_b
        elif curr_a[:2] in ["kj"]:
            curr_a, curr_b = "i" + curr_a[2:], -curr_b
        elif curr_a[:2] in ["ji"]:
            curr_a, curr_b = "k" + curr_a[2:], -curr_b
        elif curr_a[:2] in ["ik"]:
            curr_a, curr_b = "j" + curr_a[2:], -curr_b
        else:
            assert False, "weird bug"
    return (curr_a, curr_b)


g = open("C-large.in", 'r+b')
T = int(g.readline().strip())
for i in range(1, T+1):
    L, X = map(int, g.readline().strip().split())
    block = g.readline().strip()

    # g^4 == 1 for all g in Q, so it can't be equal to ijk = -1
    if X % 4 == 0:
        print "Case #%d: NO" % i
        continue

    # We have g^4 == 1 for all g in Q, but giving more room in case we need extra space to simplify.
    # Each letter needs at most block^4 if it exists, and there are 3 letters, so 4*3 = 12
    if X > 12:
        X = 12 + (X % 12)
    elt = X*block

    if len(elt) < 3:
        # print "Case #%d: NO (string too short: %s)" % (i, elt[0])
        print "Case #%d: NO" % i
        continue

    # Initialize
    cursor_i = 0
    current = ('', 1)

    # Looking for i
    found_i = False
    for x in range(0, len(elt)-2):
        current = simplify((current[0] + elt[x], current[1]))
        if current == ("i", 1):
            found_i = True
            cursor_i = x+1
            break
    if not found_i:
        # print "Case #%d: NO (couldn't find i)" % i
        print "Case #%d: NO" % i
        continue

    # print "Looking for j, cursor =", cursor_i, simplify((elt[:cursor_i], 1))

    # Looking for j
    cursor_j = cursor_i
    current = ('', 1)
    found_j = False
    for x in range(cursor_i, len(elt)-1):
        current = simplify((current[0] + elt[x], current[1]))
        if current == ("j", 1):
            found_j = True
            cursor_j = x+1
            break

    if not found_j:
        # print "Case #%d: NO (couldn't find j)" % i
        print "Case #%d: NO" % i
        continue

    # print "Looking for k, cursor =", cursor_j, simplify((elt[cursor_i:cursor_j], 1))

    cursor_k = cursor_j

    # print "Rest of string simplifies to:", (simplify((elt[cursor_k:], 1)))

    # Check if rest of string simplifies to k
    if simplify((elt[cursor_k:], 1)) == ("k", 1):
        print "Case #%d: YES" % i
    else:
        # print "Case #%d: NO (couldn't find k)" % i
        print "Case #%d: NO" % i
