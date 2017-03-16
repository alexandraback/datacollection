import math
LINES_FOR_EACH_INPUT = 1
INPUT_FILE_NAME = 'D-large.in'
OUTPUT_FILE_NAME = 'D-large.out'

def do_case(parsed_input):
        k=parsed_input[0]
        c=parsed_input[1]
        s=parsed_input[2]
        if(s*c<k):
                return "IMPOSSIBLE"
        results=""
        for i in range(int(math.ceil(k/c))):
                check=1
                for j in range(c):
                        t=(i*c+j)%k
                        check+=pow(k,j)*t
                results=results+str(check)+" "
        return str(results[:-1])

def do_parse(input):
        return [int(num) for num in input[0].rstrip().split(" ")]    

def main():
        input_f = open(INPUT_FILE_NAME, 'r')
        output = []
	
        num_of_test_cases = int(input_f.readline(), 10)
	
        input_lines = input_f.readlines()
	
        for test_case in range(num_of_test_cases):
                parsed_input = do_parse(input_lines[test_case*LINES_FOR_EACH_INPUT : (test_case + 1) * LINES_FOR_EACH_INPUT])
                output.append('Case #' + str(test_case + 1) + ': ' + do_case(parsed_input))

        output_f = open(OUTPUT_FILE_NAME, 'w')
        output_f.write('\n'.join(output))
	
        input_f.close()
        output_f.close()
	
if __name__ == '__main__':
        main()
