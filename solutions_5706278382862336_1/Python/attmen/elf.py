import math

f_input  = open('d:\gjam\\2013\elf_l.in', 'r')
f_output = open('d:\gjam\\2013\elf_output.txt', 'w')

n_test = int(f_input.readline())

for i in range(n_test):
    
    t = f_input.readline()
    param = list(map(float, t.split('/')))
    P = param[0]
    Q = param[1]


    Q_residual = Q

    while (Q_residual % 2 == 0):
        Q_residual = Q_residual / 2

    if (P % Q_residual != 0 ):
        f_output.write('Case #' + str(i+1) + ': ' + 'impossible' + '\n')
    else:
        P = P / Q_residual
        Q = Q / Q_residual
        f_output.write('Case #' + str(i+1) + ': ' + str(int(math.ceil(math.log(Q/P, 2))))+ '\n')

f_input.close()
f_output.close()
