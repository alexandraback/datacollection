################## Elena Khusainova #####################

################## Libraries ############################


######################### Main ##########################
filename = "B-small-attempt1.in"

f = open(filename, "r")
data = f.read()
f.close()

data = data.split("\n")


T = data[0]
data.remove(T)

if data[-1] == '':
    del data[-1]

for i in range(len(data)):
    temp = data[i].split(' ')
    C = list(temp[0])
    J = list(temp[1])
    Cscore = []
    Jscore = []

    while len(C) and (C[0] == '?' or J[0] == '?'):
        if C[0] == '?' and J[0] != '?':
            Cscore += [J[0]]
            Jscore += [J[0]]
            del C[0]
            del J[0]

        elif J[0] == '?' and C[0] != '?':
            Jscore += [C[0]]
            Cscore += [C[0]]
            del J[0]
            del C[0]

        elif J[0] == '?' and C[0] == '?':
            Jscore += ['0']
            Cscore += ['0']
            del J[0]
            del C[0]
            
        
        
    while len(C):
        if C[0] < J[0]:
            while len(C):
                if C[0] == '?':
                    Cscore += [9]
                    C.remove('?')
                else:
                    Cscore += [C[0]]
                    del C[0]
            while len(J):
                if J[0] == '?':
                    Jscore += [0]
                    J.remove('?')
                else:
                    Jscore += [J[0]]
                    del J[0]
        else:
            while len(C):
                if C[0] == '?':
                    Cscore += [0]
                    C.remove('?')
                else:
                    Cscore += [C[0]]
                    del C[0]
            while len(J):
                if J[0] == '?':
                    Jscore += [9]
                    J.remove('?')
                else:
                    Jscore += [J[0]]
                    del J[0]

    Jscore = [str(s) for s in Jscore]
    Cscore = [str(s) for s in Cscore]

    for j in range(len(Jscore)):
        if Jscore[j] == '?':
            Jscore[j] = '0'
        if Cscore[j] == '?':
            Cscore[j] = '0'


    with open("Problem2Small_out.txt", "a") as myfile:
        myfile.write('Case #'+str(i+1)+': '+''.join(Cscore)+' '+''.join(Jscore)+'\n')
    myfile.close()

        

