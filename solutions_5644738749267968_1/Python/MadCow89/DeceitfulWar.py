import random

def solve(input_path, output_path):
    read_weight = lambda line : sorted(map(lambda s : float(s), line.strip().split(" ")))
    with open(input_path, 'r') as fin:
        with open(output_path, 'w') as fout:
            num_cases = int(fin.readline())
            for i in xrange(num_cases):
                num_blocks = int(fin.readline())
                naomi = read_weight(fin.readline())
                ken = read_weight(fin.readline())
                fout.write("Case #" + str(i+1) + ": " + str(play_deceitful_war(naomi, ken)) + " " + str(play_war(naomi, ken)) + "\n")

def play_war(naomi, ken):
    naomi_score = 0
    used = [False for k in ken]
    for i in xrange(len(naomi)):
        ken_play = -1
        min_unused = 0
        for j in xrange(len(ken)):
            if not used[j]:
                if ken[j] < ken[min_unused]:
                    min_unused = j
                if ken[j] > naomi[i]:
                    if ken_play < 0 or (ken_play >= 0 and ken[j] < ken[ken_play]):
                        ken_play = j
        if ken_play < 0:
            ken_play = min_unused
            naomi_score += 1
        used[ken_play] = True
    return naomi_score

def play_deceitful_war(naomi, ken):
    naomi_score = 0
    used = [False for k in ken]
    i = len(naomi) - 1
    j = len(ken) - 1
    while i >=0 and j >= 0:
        if naomi[i] >ken[j]:
            i -= 1
            j -= 1
            naomi_score += 1
        else:
            j -= 1
    return naomi_score
    

dir = "F:\\Sync\\Dropbox\\Coding\\CodeJam\\2014\\"
input_path = dir + "D-large.in"
output_path = dir + "D-large.out"
solve(input_path, output_path)


