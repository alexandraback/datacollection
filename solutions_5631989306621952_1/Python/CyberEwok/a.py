def solve(in_file, out_file):
    trials=int(in_file.readline())
    for trial in range(1, trials + 1):
        word = in_file.readline().strip()
        final = ""
        for c in word:
            if final + c < c + final:
                final = c + final
            else:
                final = final + c
        out_file.write("Case #{}: {}\n".format(trial, final))

if __name__ == '__main__':
    path='Data\\'
    #name='A-sample'
    #name='A-small-attempt0'
    name='A-large'
    raw=open(path+name+'.in', 'r')
    wrt=open(path+name+'.out','w')
    solve(raw, wrt)
    raw.close()
    wrt.close()