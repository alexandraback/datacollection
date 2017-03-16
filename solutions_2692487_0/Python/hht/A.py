import sys

def solve(mysize, others, i, ans):
    if (i == len(others)):
        return ans
    other_size = int(others[i])

    if (mysize > other_size):
        mysize += other_size
        ans = solve(mysize, others, i + 1, ans)
    else:
        add_size = mysize - 1

        if (mysize + add_size > other_size):
            ans += 1
            mysize = mysize + add_size + other_size
            ans = solve(mysize, others, i + 1, ans)
        else:
            ans += 1
            ans1 = solve(mysize, others, i + 1, ans)
            if (add_size > 0):
                ans2 = solve(mysize + add_size, others, i, ans)
                ans1 = min(ans1, ans2)
            ans = ans1
    return ans



if __name__ == "__main__":
    fin = open('A-small-attempt2.in', 'r')
    case_num = int(fin.readline())
    ans = 0
    fout = open('A.txt', 'w')
    for case_id in range(1, case_num + 1):
        next_line = fin.readline().strip()
        next_line = next_line.split(' ')
        mysize = next_line[0]
        num_others = next_line[1]
        others = fin.readline().strip()
        others = others.split(' ')
#        print (next_line)
#        print (others)
        for i in range(0, len(others)):
            others[i] = int(others[i])

        others.sort()
        mysize = int(mysize)
        ans = solve(mysize, others, 0, 0)

#        print (("Case #%d: %d\n") % (case_id, ans))

        fout.write (("Case #%d: %d\n") % (case_id, ans))
    fout.close()
        
