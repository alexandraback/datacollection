directory = 'C:/users/hai/my projects/google code jam/2012/1C/A/'


def solve (f_in, f_out):
    T = int(f_in.readline())
    for testcase in range(1,T+1):
        N  = int(f_in.readline())
        nodes_parents = [None for i in range(N+1)]
        nodes_reaches = [[] for i in range(N+1)]
        for i in range(1,N+1):
            nodes_parents[i] = [int(x) for x in f_in.readline().split()[1:]]

        try:
            answer = 'No'
            for i in range(1,N+1):
                walk (nodes_parents, nodes_reaches, i, i)
        except ValueError:
            answer = 'Yes'

        f_out.write('Case #' + str(testcase) + ': ' + answer + '\n')
        


def walk (nodes_parents, nodes_reaches, initiating_node, curr):
    if initiating_node != curr:
        if initiating_node in nodes_reaches[curr]:
            raise ValueError
        nodes_reaches[curr].append(initiating_node)
    for nextnode in nodes_parents[curr]:
        walk (nodes_parents, nodes_reaches, initiating_node, nextnode)








def main_run():
    import os
    import time
    filenames = [x for x in os.listdir (directory)]
    filenames = [x for x in filenames if x.endswith('.in')]
    l1 = [(os.stat(directory+x).st_ctime, x) for x in filenames]
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


