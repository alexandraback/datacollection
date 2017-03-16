import java.io.PrintWriter;
import java.util.Scanner;

public class A extends Template {
    public static void main(String[] args) {
        new A();
    }
    @Override
    protected void run(Scanner scanner, PrintWriter writer) {
        String line = scanner.nextLine();
        int[] numbers = new int[10];
        numbers[4] = count(line, 'U');
        numbers[5] = count(line, 'F') -  numbers[4];
        numbers[7] = count(line, 'V') - numbers[5];
        numbers[2] = count(line, 'W');
        numbers[0] = count(line, 'Z');
        numbers[1] = count(line, 'O') - numbers[0] -  numbers[2] - numbers[4];
        numbers[6] = count(line, 'X');
        numbers[9] = (count(line, 'N') - numbers[1] - numbers[7])/2;
        numbers[8] = count(line, 'I') - numbers[5] - numbers[9] - numbers[6];
        numbers[3] = count(line, 'T') - numbers[2] - numbers[8];
        for(int i = 0; i <10; ++i) {
            print(i, numbers[i], writer);
        }
        writer.println();

    }

    public void print(int number, int count, PrintWriter writer) {
        for(int i = 0; i < count; ++i) {
            writer.print(number);
        }
    }

    public int count(String line, char needle) {
        int count = 0;
        for(int i = 0; i < line.length(); ++i) {
            if(line.charAt(i) == needle) {
                count++;
            }
        }
        return count;
    }
}
