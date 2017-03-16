def get_result(A,B,probs):
    result = 0 
    
    exps = [0 for i in range(int(A+2))]
    prob_correct = reduce(lambda x,y:x*y, probs)
    
    partials = [1 for i in range(A)]
    partials[0] = probs[0]
    for i,elem in enumerate(partials[1:]):
        partials[i+1] = partials[i] * probs[i+1]
        
    for j,elem in enumerate(exps[:A-1]):
        right_cost = 2 * (j+1) + (B-A) + 1
        wrong_cost = right_cost + B + 1
        exps[j] = partials[len(partials)-j-2] * right_cost + (1 - partials[len(partials)-j-2]) * wrong_cost
    
    exps[A-1] = A + B + 1            
    exps[A] = (B-A+1) * prob_correct + (2*B - A + 2) * (1 - prob_correct)
    exps[A+1] = B + 2
    
    return min(exps)

def solve():
        
    file_in = file("A-large.in")
    file_out = file("A-large.out","w")
    num_of_cases = int(file_in.readline())
    
    for j in range(num_of_cases):
        line = file_in.readline()
        
        line = line.strip().split()
        
        A = int(line[0])
        B = int(line[1])
        
        probs = file_in.readline()
        probs = probs.strip().split()
        probs = [float(i) for i in probs]
        
        result = str(get_result(A,B,probs))
        
        file_out.write("Case #%d: %s\n" % ((j+1),result))    
        
    
    file_out.close()
        

if __name__ == '__main__':
    solve()