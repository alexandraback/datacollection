directory = 'C:/users/hai/my projects/google code jam/2013/round1b/A/'



def solve (f_in, f_out):
    T = int(f_in.readline())
    for testcase in range(1,T+1):
        print (testcase)
        A,N = [int(x) for x in f_in.readline().split()]
        s = [int(x) for x in f_in.readline().split()]
        s.sort()
        sugg = [len(s)]
        if A == 1 and s[0] >=1:
            pass
        else:
            moves = 0
            while s:
                while A <= s[0]:
                    moves += 1
                    A = A*2-1
                A += s[0]
                s = s[1:]
                sugg.append(moves + len(s))
        result = min(sugg)
        f_out.write('Case #' + str(testcase) + ': '+ str(min(sugg)) + '\n')









def main_run():
    import os
    import time
    filenames = [x for x in os.listdir (directory)]
    filenames = [x for x in filenames if x.endswith('.in')]
    l1 = [(os.stat(directory+x).st_mtime, x) for x in filenames]
    chosen_filename =  sorted(l1)[-1][1][:-3]

    print ('Directory : ', directory)
    print ('Chosen Filename : ',chosen_filename)
    print()
    print ('Start : ', time.ctime())
    print()
    
    f_in = open(directory+chosen_filename+'.in')
    f_out = open(directory+chosen_filename+'.out', 'w')
    solve(f_in,f_out)
    f_in.close()
    f_out.close()

    print ()
    print ('End : ', time.ctime())


main_run()
