from copy import copy

output = open("outputDSmall.txt", "w")
file = open("D-small-attempt0.in")

#Ken will chose a block that is slightly better than naomi's
#If no such blocks exist, then Ken will play his worse block
def choose_block(sorted_blocks, given_block):
    #If Ken's biggest block is not big enough, he will play his smallest block
    if sorted_blocks[-1] < given_block:
        return sorted_blocks.pop(0) #Remove and return the smallest block
    else: #He must have a block worth playing
        #I would normally use a binary search here, but to me it seems that it might not actually be necessary in this case
        #Go backwards until we hit a block that is too small
        for j in reversed(range(0, len(sorted_blocks))):
            ken_block = sorted_blocks[j]
            if ken_block < given_block:
                return sorted_blocks.pop(j+1) #We know that the previous block was big enough
        #All the blocks were big enough so we fell out of loop. Return first block
        return sorted_blocks.pop(0)

#Naomi needs to choose something to say that isn't the same as one of Ken's blocks (including that have already been played?)
#And that won't result in a weight contradiction
#The strategy is to make Ken waste his good blocks early on
def what_should_naomi_say(ken_blocks_cheat, naomi_chose, all_ken_blocks):
    #If Naomi's block is worse than all of Ken's blocks, then Naomi will wipe out Ken's best block
    if naomi_chose < ken_blocks_cheat[0]:
        return ken_blocks_cheat[-1] - 0.000001 #She will say it is SLIGHLY worse
    elif naomi_chose > ken_blocks_cheat[-1]: #If naomi's block is better than all of Ken's, she can tell the truth
        return naomi_chose
    elif naomi_chose > ken_blocks_cheat[0]: #Ken does have a worse block, she needs to make him think he doesn't
        return 0.9999999


N = int(file.readline())
for i in range(1, N+1):

    #Read the data
    blocks_each = int(file.readline())
    naomi_blocks = [float(x) for x in file.readline().split()]
    ken_blocks = [float(x) for x in file.readline().split()]
    ken_blocks.sort()

    #Firstly, what is the score when naomi does not cheat?
    naomi_score_normal = 0
    naomi_blocks_normal = list(naomi_blocks)
    ken_blocks_normal = list(ken_blocks)
    while len(naomi_blocks_normal) != 0:
        naomi_chose = naomi_blocks_normal.pop() #I think it said that it doesn't matter what strategy she uses
        ken_chose = choose_block(ken_blocks_normal, naomi_chose)
        if naomi_chose > ken_chose:
            naomi_score_normal += 1
            
    #Now, what is the score when naomi cheats?
    naomi_score_cheat = 0
    naomi_blocks_cheat = list(naomi_blocks)
    ken_blocks_cheat = list(ken_blocks)
    naomi_blocks_cheat.sort()
    while len(naomi_blocks_cheat) != 0:
        naomi_chose = naomi_blocks_cheat.pop(0) #Namoi will always play her worst block
        naomi_says = what_should_naomi_say(ken_blocks_cheat, naomi_chose, ken_blocks)
        ken_chose = choose_block(ken_blocks_cheat, naomi_says)
        if naomi_chose > ken_chose:
            naomi_score_cheat += 1
    output.write("Case #" + str(i) + ": " + str(naomi_score_cheat) + " " + str(naomi_score_normal) + "\n")
            
output.close()    
