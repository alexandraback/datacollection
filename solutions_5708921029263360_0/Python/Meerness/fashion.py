__author__ = 'User'

def check_pair(K, pairs, outfit):
    if outfit in pairs and pairs[outfit] == K:
        return False
    if outfit not in pairs:
        pairs[outfit] = 0
    return True

def make_outfits(input_list):
    J, P, S, K = input_list
    JSpairs = [[0]*S for _ in range(P)]
    PSpairs = [[0]*S for _ in range(P)]
    outfits = []
    for j in range(J):
        for p in range(P):
            for _ in range(min(S, K)):
                min_JS = min(JSpairs[j])
                s_JS = JSpairs[j].index(min_JS)
                min_PS = min(PSpairs[p])
                s_PS = JSpairs[j].index(min_JS)
                if min_JS + PSpairs[p][s_PS] <= min_PS + JSpairs[j][s_PS]:
                    s = s_JS
                    PSpairs[p][s_PS] += 1
                    JSpairs[j][s] += 1
                else:
                    s = s_PS
                    JSpairs[j][s_PS] += 1
                    PSpairs[p][s] += 1
                outfits.append("{} {} {}".format(j+1, p+1, s+1))
    return outfits

with open("input.txt", "r") as file:
    with open("result.txt", "w") as write_file:
        for i, line in enumerate(file):
            if i == 0:
                continue
            input_list = line.strip().split(' ')
            x = make_outfits(int(x) for x in input_list)
            write_file.write("Case #{}: {}\n{}\n".format(i, len(x), "\n".join(x)))