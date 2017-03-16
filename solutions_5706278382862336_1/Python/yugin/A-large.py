# GCJ Round 1C A-Small

infile = open('A-large.in','r')
outfile = open('A-large.txt','w')

cases = infile.readline()

for case in range(1,int(cases)+1):
    fraction = infile.readline()
    line = fraction.split('/')
    if fraction == '1/1':
        result = 0
    elif fraction == '0/1':
        result = 'impossible'
    else:
        gen = [1]
        i = 0
        gen_sum = 1
        fraction = int(line[0]) / int(line[1])
        while gen_sum <= 40:
            if fraction == 0.5:
                break
            elif fraction < 0.5:
                fraction = fraction * 2
                gen[i] += 1
            else:
                i += 1
                gen.append(1)
                fraction = 2 * fraction - 1
            gen_sum = 0
            for number in gen:
                gen_sum += number
        if gen_sum <= 40:
            result = gen[0]
        else:
            result = 'impossible'
    outfile.write('Case #{0}: {1}'.format(str(case),str(result)))
    outfile.write('\n')

infile.close()
outfile.close()
                
                
