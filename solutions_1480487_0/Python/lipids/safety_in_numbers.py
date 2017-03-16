from decimal import *

def compare(score1, score2):
    if score1 == False:
        return False
    else:
        if abs(score1 - score2)<0.000001:
            return True
        else:
            return False

def min_scores(judges_scores, scale, minimum = 0, maximum = -1):
    x = sum(judges_scores)
    jmin = min(judges_scores)
    print x
    greater_than = False
    if maximum == -1:
        maximum = x
    if minimum == 0:
        minimum = jmin
    #print [minimum + scale*i for i in range(0, int(maximum*(1/scale)+(2/scale)))]
    for i in [minimum + scale*i for i in range(0, int(maximum*(1/scale)+(2/scale)))]:
        audience_probs = []
        for score in judges_scores:
            s = float(i - score)/float(x)
            if s<0:
                audience_probs.append(Decimal(0))
            else:
                audience_probs.append(Decimal(i - score)/Decimal(x))
        #print audience_probs
        if abs(sum(audience_probs)-1)<=0.000001:
            return [p*100 for p in audience_probs]
        if sum(audience_probs)>1:
            return min_scores(judges_scores, scale/100, i-scale, i)
            
       

print min_scores([20,10], 0.1)
print min_scores([10,0], 0.1)
print min_scores([25,25,25,25], 0.1)
print min_scores([24,30,21], 0.1)
print min_scores([49, 35, 35, 100, 37, 41, 39, 34, 43, 49], 0.1)


input_file = open('A-small-attempt3.in')
output_file = open('output', 'w')
for i, line in enumerate(input_file.readlines()):
    if i==0:
        continue
    else:
        pass
        #do something relevant
        numbers = map(int, line.split())[1:]
        print numbers
        min_votes = min_scores(numbers, 0.1)
        print min_votes
        output_string = ''
        if min_votes is not None:
            output_string = ' '.join([str(a) for a in min_votes])
        output_file.write('Case #%d: %s\n' % (i, output_string))
input_file.close()
output_file.close()

