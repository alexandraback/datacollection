f = open("d0.in", 'r')
f_out = open("out_D", 'w')

cases = f.readline()

for case in range(int(cases)):
    f.readline()
    n_blocks = f.readline().split()
    k_blocks = f.readline().split()
    n_blocks.sort()
    k_blocks.sort()

    n_blocks_copy = n_blocks[:]
    k_blocks_copy = k_blocks[:]
    #dwar
    dwar_res = 0
    while len(n_blocks_copy) > 0:
        if n_blocks_copy[0] > k_blocks_copy[-1]:
            dwar_res += len(n_blocks_copy)
            break
        elif n_blocks_copy[0] > k_blocks_copy[0]:
            n_blocks_copy.pop(0)
            k_blocks_copy.pop(0)
            dwar_res += 1
        else:
            n_blocks_copy.pop(0)
            k_blocks_copy.pop()

    res = 0
    while len(n_blocks) > 0:
        if n_blocks[-1] > k_blocks[-1]:
            res += 1
            n_blocks.pop()
            k_blocks.pop(0)
        else:
            n_blocks.pop()
            k_blocks.pop()
    print "Case #" + str(case + 1) + ": " + str(dwar_res) + ' ' + str(res)
    f_out.write("Case #" + str(case + 1) + ": " + str(dwar_res) + ' ' + str(res) + '\n')


    # teraz normalna wojna