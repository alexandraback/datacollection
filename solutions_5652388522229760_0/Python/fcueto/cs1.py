# Fernando Gonzalez del Cueto
# Google Code Jam 2016

# fname_in = r"test.in"
fname_in = r"A-small-attempt0.in"
fname_out = fname_in.replace('.in', '.out')

fin = open(fname_in,'r')
fout = open(fname_out, 'w')

def update_set(s, my_set):
    # digits = initial_set

    for c in s:
        if c not in my_set:
            my_set.add(c)
        if len(my_set)==10:
            break
    return my_set


def fun2(n):
    if n==0:
        return 'INSOMNIA'
    else:
        k = n
        digits = set()
        next_num = 0
        while True:
            next_num += n
            # digits = str2set(str(next_num), digits)
            update_set(str(next_num), digits)
            if len(digits)==10:
                break
        return next_num

n_tests = int(fin.readline().strip())

for case_j in range(1,n_tests+1):

    n = int(fin.readline().strip())
    result = fun2(n)

    line_output = "Case #%i: %s" % (case_j, result)
    print(line_output)

    fout.writelines([line_output, '\n'])

fin.close()
fout.close()