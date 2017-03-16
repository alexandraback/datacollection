import copy


######################### Helper Functions #######################################################################
def count_score(a_in, b_in):  #a's score if a is player1 in regular War (a has to say real weight)
    a = copy.deepcopy(a_in)
    b = copy.deepcopy(b_in)
    counter = 0
    while (len(a) != 0):
        a_score = a.pop(0)
        b_score = 0
        for block in b:
            if (block > a_score):
                b_score = block
                break
        if (b_score == 0):
            b.pop(0)
            counter += 1
            continue
        b.remove(b_score)
        continue
    return counter








#################################################################################################################


input = open("D-small-attempt0.in","r")
inputlist = input.readlines()
input.close()

length_input = len(inputlist)
numberofplays = int(inputlist[0])

output = open("D-small-attempt0.out","w+")

case = 1

while (case <= numberofplays):
    naomi_blocks = [] ##############################################################################################
    ken_blocks = []
    case_pointer = -1 + 3*case
    num_blocks_each = int(inputlist[case_pointer-1])
    naomi_blocks_temp = inputlist[case_pointer].split(" ")  ########################################################
    ken_blocks_temp = inputlist[case_pointer+1].split(" ")  ##### extract information and sort; naomi_blocks and ken_blocks
    for item in naomi_blocks_temp:                          ########################################################
        naomi_blocks.append(float(item))
    for item in ken_blocks_temp:
        ken_blocks.append(float(item))
    naomi_blocks.sort()
    ken_blocks.sort()  #############################################################################################
    
    score1 = count_score(naomi_blocks, ken_blocks)
    score2 = num_blocks_each - count_score(ken_blocks, naomi_blocks)
    #print(naomi_blocks)
    #print(ken_blocks)
    #print(score1)
    #print(score2)

    output.write("Case #{0}: {1} {2}\n".format(case, score2, score1))
    case += 1
    
output.close()
