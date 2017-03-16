num_tests = int(input())
for n in range(num_tests):
    j, p, s, k = list(map(int, input().split()))
    all_outfits = [[j_, p_, s_] for j_ in range(1, j + 1) for p_ in range(1, p + 1) for s_ in range(1, s + 1)]
    combos = {tuple(x[:y] + [0] + x[y+1:]): 0 for x in all_outfits for y in range(3)}
    max_outfits = 0
    outfits = []
    for outfit in all_outfits:
        o_combos = [tuple(outfit[:y] + [0] + outfit[y+1:]) for y in range(3)]
        failed = False
        for oc in o_combos:
            if combos[oc] + 1 > k:
                failed = True
                break
        if not failed:
            for oc in o_combos:
                combos[oc] += 1
            outfits.append(list(map(str, outfit)))
            max_outfits += 1
    print('Case #{}: {}\n{}'.format(n + 1, max_outfits, '\n'.join([' '.join(o) for o in outfits])))
