from collections import defaultdict

def solve(j, p, s, k):
    as_list_of_lists = solve_(j, p, s, k)
    #print as_list_of_lists
    map_fun = lambda x: ' '.join(x)
    as_list_of_strings = map(map_fun, as_list_of_lists)
    length = str(len(as_list_of_strings))
    answer = [length]
    answer.extend(as_list_of_strings)
    return '\n'.join(answer)

def solve_(j, p, s, k):
    max_poss_outfits = j * p * s
    max_pairs = p*s*k #as j not greater than these
    j_p_dict = defaultdict(int)
    j_s_dict = defaultdict(int)
    p_s_dict = defaultdict(int)

    outfit_list = []
    for jacket in range(1, j + 1):
        for pants in range(1, p + 1):
            for shirt in range(1, s + 1):
                #print "jp dict:", j_p_dict[(jacket, pants)]
                using = True
                shirt = shirt + jacket - 1 + pants - 1#need to rotate
                if shirt > s:
                    shirt = shirt - s
                if shirt > s: #horrible
                    shirt = shirt - s
                if j_p_dict[(jacket, pants)] == min(k, s):
                    break #no point trying more shirts
                if j_s_dict[(jacket, shirt)] == min(k, p): #hmm, p superflous?
                    using = False
                if p_s_dict[(pants, shirt)] == min(k, j):#j
                    using = False
                if using:
                    outfit_list.append([str(jacket),str(pants),str(shirt)])
                    j_p_dict[(jacket, pants)] += 1
                    j_s_dict[(jacket, shirt)] += 1
                    p_s_dict[(pants, shirt)] += 1
    return outfit_list

    
if __name__=="__main__":
    t = int(raw_input())  # read a line with a single integer
    for i in xrange(1, t + 1):
        j, p, s, k = [int(s) for s in raw_input().split(" ")]  # read a list of integers, 2 in this case
        print "Case #{}: {}".format(i, solve(j, p, s, k))
          # check out .format's specification for more formatting options
