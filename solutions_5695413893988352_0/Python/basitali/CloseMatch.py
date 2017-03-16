def minimum_scores(coder, jammer):

    if coder == "?" or jammer == "?":
        jammer = coder = "0"
        return " ".join([coder, jammer])
        
    if coder == "?" or jammer == "?":
        if coder == "?":
            coder = jammer
        else:
            jammer = coder

        return " ".join([coder, jammer])

    coder = list(coder)
    jammer = list(jammer)

    ending_length = 0
    for i in xrange(len(coder) - 1, -1, -1):
        if coder[i] == "?" and jammer[i] == "?":
            ending_length += 1
        else:
            break
    
    if ending_length == len(coder):
        coder = jammer = "0" * len(coder)
        return " ".join([coder, jammer])

    start_length = len(coder) - ending_length

    # Fill in knowns
    for i in xrange(start_length):
        if coder[i] == "?" and jammer[i] == "?":
            coder[i] = "0"
            jammer[i] = "0"
        # elif coder[i] == "?" or jammer[i] == "?":
        #     if jammer[i] == "?":
        #         jammer[i] = coder[i]
        #     else:
        #         coder[i] = jammer[i]
        else:
            break

    for i in xrange(0, len(coder) - 1):
        if coder[i] == "?" or jammer[i] == "?":
            if coder[i] == "?":
                coder[i] = jammer[i]
            else:
                jammer[i] = coder[i]

        if coder[i + 1] != "?" and jammer[i + 1] != "?":
            continue

        coder_num = int("".join(coder[:i + 1]))
        jammer_num = int("".join(jammer[:i + 1]))

        if coder_num == jammer_num:
            if coder[i + 1] == "?" and jammer[i + 1] == "?":
                coder[i + 1] = "0"
                jammer[i + 1] = "0"
            elif coder[i + 1] == "?":
                coder[i + 1] = jammer[i + 1]
            else:
                jammer[i + 1] = coder[i + 1]

            continue

        if coder_num > jammer_num:
            bigger_num = coder_num
            smaller_num = jammer_num

            bigger_list = coder
            smaller_list = jammer
        else:
            bigger_num = jammer_num
            smaller_num = coder_num

            bigger_list = jammer
            smaller_list = coder

        if bigger_list[i + 1] == "?" and smaller_list[i + 1] == "?":
            bigger_list[i + 1] = "0"
            smaller_list[i + 1] = "9"
        elif bigger_list[i + 1] == "?":
            bigger_list[i + 1] = "0"
        else:
            smaller_list[i + 1] = "9"

        # print "bigger_num", bigger_num
        # print "smaller_num", smaller_num

    return " ".join(["".join(coder), "".join(jammer)])

if __name__ == '__main__':
    case = 'B-sample'
    case = 'B-small-attempt1'
    # case = "B-large"

    inp = open('%s.in'%case)
    out = open('%s.out'%case, 'w')

    cases = int(inp.readline())
    for i in xrange(1, cases + 1):
        coder, jammer = inp.readline().split()

        o = "Case #%d: %s"%(i, str(minimum_scores(coder, jammer)))
        print o
        out.write('%s'%o)
        if i < cases:
            out.write('\n')
