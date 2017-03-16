# Fernando Gonzalez del Cueto
# Google Code Jam 2016

#fname_in = r"test.in"
# fname_in = r"A-small-attempt0.in"
fname_in = r"A-large.in"
fname_out = fname_in.replace('.in', '.out')

fin = open(fname_in,'r')
fout = open(fname_out, 'w')

def myfun(n):

    if n==0:
        return 'INSOMNIA'
    else:

        if n==2:
            pass

        n_s = str(n)
        nlen = len(n_s)

        curr_num = n
        digits = set(n_s)

        while len(digits) < 10:

            curr_num += n
            curr_s = str(curr_num)

            max_search_len = min(len(curr_s), nlen+1)
            for k in range(1, max_search_len + 1):
                c = curr_s[-k]
                digits.update(c)

                if len(digits) == 10:
                    break

        return curr_num

n_tests = int(fin.readline().strip())

for case_j in range(1,n_tests+1):

    n = int(fin.readline().strip())
    result = myfun(n)

    line_output = "Case #%i: %s" % (case_j, result)
    print(line_output)

    fout.writelines([line_output, '\n'])

fin.close()
fout.close()