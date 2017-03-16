# IO file paths
file_in = "B-large.in"
file_out = "B-large.out"

# Initial cookie provisioning speed
initial_speed = 2.0

# Solves the problem
def Solve(C, F, X):
    sp = initial_speed
    
    if X <= C:
        return X / sp
    
    time = 0.0
    # While we keep vuying factories
    while True:
        # Verify whether it makes sense to buy a factory
        if F * (X - C) > C * sp:
            # Incerment the total time
            time = time + C / sp
            # Buy a factory
            sp = sp + F
            continue
        # We are not buying a factory
        time = time + X / sp
        break
    return time
    
    
# Reads the input data and runs the test cases
def Run():
    fin = open(file_in, 'r')
    fout = open(file_out, 'w')

    lines = []
    for l in fin:
        lines.append(l)

    i = 0
    T = int(lines[0])
    i = i + 1
    for t in range(0, T):
        values = lines[i].rstrip().split(' ')
        i = i + 1
        C = float(values[0])
        F = float(values[1])
        X = float(values[2])
        # Outputting to 7 decimal places
        result = str("%.7f" % Solve(C, F, X))
        fout.write("Case #" + str(t + 1) + ": " + result + '\n')
        
    fin.close()
    fout.close()
    

def main():
    Run()

if __name__ == "__main__":
    main()
