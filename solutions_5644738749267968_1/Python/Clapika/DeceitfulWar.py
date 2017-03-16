__author__ = 'Clapika'

fin = open('input', "r+")
fout = open('output', "w")

n = int(fin.readline())
for i in range(n):
    block_num = int(fin.readline())
    naomi_block = [float(x) for x in fin.readline().split()]
    ken_block = [float(x) for x in fin.readline().split()]
    naomi_block.sort()
    ken_block.sort()
    naomi_score1 = 0
    naomi_score2 = 0
    temp = ken_block[:]
    for block in naomi_block:
        if block < min(ken_block):
            ken_block.pop()
        else:
            naomi_score1 += 1
            ken_block.pop(0)
    ken_block = temp

    for block in naomi_block:
        if block > max(ken_block):
            ken_block.pop(0)
            naomi_score2 += 1
            continue
        else:
            for k_block in ken_block:
                if k_block > block:
                    ken_block.remove(k_block)
                    break
    fout.write("Case #%d: %d %d\n" % ((i + 1), naomi_score1, naomi_score2))

