def d_war(n_blocks, k_blocks):
    score = 0
    while len(n_blocks) > 0:
        if n_blocks[0] < k_blocks[0]:
            k_blocks = k_blocks[:-1]
        else:
            score += 1
            k_blocks = k_blocks[1:]
        n_blocks = n_blocks[1:]

    return score

def war(n_blocks, k_blocks):
    n_counter, k_counter = 0, 0
    N = len(n_blocks)

    while n_counter < N and k_counter < N:
        if n_blocks[n_counter] < k_blocks[k_counter]:
            n_counter += 1
        k_counter += 1
    return k_counter - n_counter

result = ''
with open('input.txt') as f:
    cases = int(f.readline()[:-1])

    for case in range(cases):
        case += 1
        N = int(f.readline()[:-1])

        n_blocks = f.readline()[:-1].split()
        n_blocks = [float(n) for n in n_blocks]
        k_blocks = f.readline()[:-1].split()
        k_blocks = [float(n) for n in k_blocks]
        n_blocks, k_blocks = sorted(n_blocks), sorted(k_blocks)

        d_score = d_war(n_blocks, k_blocks)
        w_score = war(n_blocks, k_blocks)

        result += "Case #%s: %s %s\n" % (case, d_score, w_score)
with open('output.txt', 'w') as f:
    f.write(result)