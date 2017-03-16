################## Elena Khusainova #####################

################## Libraries ############################


######################### Main ##########################
filename = "C-small-attempt1.in"

f = open(filename, "r")
data = f.read()
f.close()

data = data.split("\n")


T = data[0]
data.remove(T)

if data[-1] == '':
    del data[-1]

it = 1

while len(data):
    N = int(data[0])
    del data[0]
    temp = []
    for i in range(N):
        temp.append(data[0])
        del data[0]

    #print(temp)

    first = [s.split(' ')[0] for s in temp]
    second = [s.split(' ')[1] for s in temp]

    goodlist = []
    first_good = []
    second_good = []

    for tp in temp:
        temp2 = tp.split(' ')
        if len([s for s in first if s == temp2[0]]) == 1:
            goodlist += [tp]
            #print("Added1:", tp)
            temp.remove(tp)
            first_good += [temp2[0]]
            second_good += [temp2[1]]
            
        if len([s for s in second if s == temp2[1]]) == 1:
            if tp not in goodlist:
                goodlist += [tp]
                #print("Added2:", tp)
                temp.remove(tp)
                first_good += [temp2[0]]
                second_good += [temp2[1]]

            
    for tp in temp:
        temp2 = tp.split(' ')
        if temp2[0] not in first_good and temp2[1] not in second_good:
            #print(temp2, first_good, second_good)
            goodlist += [tp]
            #print("Added3:", tp)
            temp.remove(tp)
            first_good += [temp2[0]]
            second_good += [temp2[1]]

    for tp in temp:
        temp2 = tp.split(' ')
        if temp2[0] not in first_good:
            goodlist += [tp]
            #print("Added4:", tp)
            temp.remove(tp)
            first_good += [temp2[0]]
            
        if temp2[1] not in second_good:
            if tp not in goodlist:
                goodlist += [tp]
            #print("Added5:", tp)
            try:
                temp.remove(tp)
            except:
                #print ('Achtung!', tp, temp, goodlist, first_good, second_good, '\n')
                print(it)
            second_good += [temp2[1]]

    answer = N - len(goodlist)

    with open("Problem3Small_out.txt", "a") as myfile:
        myfile.write('Case #'+str(it)+': '+str(answer)+'\n')
    myfile.close()

    it+= 1

        

