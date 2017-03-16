#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <math.h>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <vector>
#include <inttypes.h>
//#include "phi.h"
//#include "item.h"
//#include <Windows.h>

using namespace std;

string convertInt(long long int);

bool isPrime(long long int x){
    if(x == 2)return true;
    if(x % 2 == 0) return false;
    if(x < 2)return false;

    long long int prime = 2;
    long long int range = x;
    while(prime <= range){
        if(x % prime == 0)
            return false;
        prime++;
        range = x / prime;
    }
    return true;
}

long long int fact(int x){
    long long int a = 1;
    for(int i = 1;i <= x; i ++){
        a *= i;
    }
    return a;
}

bool pandigital(string s){
    //checker init
    string checker = "9876543210";
    for(int i = 0; i < checker.length(); i++){
        for(int j = 0; j < s.length(); j++){
            if(checker[i] == s[j]){
                break;
            }
            if(checker[i] != s[j] && j == s.length()-1){
                return false;
            }

        }
    }
    return true;
}

long long int manual_pow(int x, int pow){
    long long int a = 1;
    while(pow != 0){
        a*=x;
        pow--;
    }
    return a;
}

char itoc(int x){
    switch(x){
        case 0:return '0';
        case 1:return '1';
        case 2:return '2';
        case 3:return '3';
        case 4:return '4';
        case 5:return '5';
        case 6:return '6';
        case 7:return '7';
        case 8:return '8';
        case 9:return '9';
    }
}


bool concat_prime(int a, int b){
    string aS = convertInt(a);
    string bS = convertInt(b);
    string resultS = aS+bS;
    int resultI = atoi(resultS.c_str());
    if(!isPrime(resultI))return false;
    resultS = bS+aS;
    resultI = atoi(resultS.c_str());
    if(!isPrime(resultI))return false;
    return true;
}

bool similiar(long long int a, long long int b){
    string aS = convertInt(a);
    string bS = convertInt(b);
    if(aS.length() != bS.length())return false;//cout << '!';
    //cout << aS << endl << bS << endl;
    for(int i = 0; i < aS.length(); i++){
        //bool next = false;
        for(int j = 0; j < bS.length(); j++){
            if(aS[i] == bS[j]){
                bS[j] = 'x';
                aS[i] = 'x';
                //next = true;
                break;
            }
            if(j == bS.length()-1 && aS[i] != bS[j]){
                //cout << aS[i] << "\t" << bS[j] << endl;
                return false;
            }
        }
    }
    return true;
}

void shiftRight(int *queens, int size){
    for(int i = 0; i < size; i++){
        queens[i] += 1;
        if(queens[i] > size)
            queens[i] = 1;
    }
}

bool str8Line(int *queens, int level, int size, int k){

}

bool queensRevised(int *queens, int size, int level){

}

int GCF(int a, int b) {
    if(a % b == 0) {
        return b;
    }
    else {
        //cout<<a<<" % "<<b<<" --> "<<a % b<<endl;
        return GCF(b, a % b);
    }
}

void middle(int n1, int d1, int n2, int d2, int &count){
    double value1 = 1.0*n1/d1;
    double value2 = 1.0*n2/d2;

    count++;
    cout << n1 << " / " << d1 << " "<< count << endl;
    //search for value bet this two exist or not.
    int newT = n2;
    int newB = d2;

    for(int bot = 12000; bot > 1; bot--){//bot must be as big as possible
        for(int top = bot*newT/newB; top <= bot*newT/newB+1; top++){//top must be as small as possible
            double newValue = 1.0*top/bot;

            if(newValue > 1.0*newT/newB || bot < top)
                break;

            if(newValue < 1.0*newT/newB && newValue > value1){
                newT = top;
                newB = bot;
                int gcf = GCF(newT, newB);
                if(gcf != 1){
                    newT /= gcf;
                    newB /= gcf;
                }
            }
        }
        if(newT == 1 && bot < newB)
            break;
    }

    if(newT == n2)
    if(newB == d2)
        return;

    //if(newT == 3 && newB == 7)return;
    middle(newT, newB, n2, d2, count);
}

/*void middle2(int n1, int d1, int n2, int d2, int &count){
    double min = 1.0*n1/d1;
    double max = 1.0*n2/d2;
    for(int bot = 12000; bot >= 2; bot--){
        cout << bot << endl;
        for(int top = 1; top < 12000; top++){
            double mid = 1.0*top/bot;
            if(mid > min && mid < max){//cout << "!";
                if(binary_gcd(top, bot) == 1){
                    count++;
                }
            }
        }
    }
}*/

bool stuckChain60(int *facts, int x){
    long long int sixty[60];
    int count = 0;

    long long int next = x;
    while(true){
        long long int copy = next;
        next = 0;
        while(copy != 0){
            next += facts[copy % 10];
            copy /= 10;
        }
        if(next == x)
            return false;//loop

        //check repeat
        bool stuck = false;
        for(int i = 0; i < count; i++){
            if(next == sixty[i]){
                stuck = true;
                //cout << count+1 << endl;

                if(count +1 != 60)
                    return false;
                else
                    return true;
            }
        }

        //no repeat
        if(count+1 >= 61)return false;
        sixty[count] = next;
        count++;

        //break;
    }
}

bool oneIntSided(int length){
    int count = 0;
    for(int a = 1; a < length/3; a++){
        //if(length%a != 0)continue;
        int b = (length*length-2*a*length)/(2*length-2*a);
        double c = sqrt(a*a+b*b);
        if(a+b+c == length){
            //cout << a << " " << b << " " << c << endl;
            count++;
            if(count == 2)
                return false;
        }
    }

    if(count == 0)return false;
    return true;
}

void parasAppend(char *paras){
    for(int a = 1; a < 1500000/3; a++){
        cout << a << endl;
        for(int b = a+1; b < 1500000/2; b++){
            double dC = sqrt(a*a+b*b);
            int c = dC;
            if(dC - c == 0){
                int length = a+b+c;
                paras[length-1]++;
            }
        }
    }
}

void array_pow(int x, int pow, int *array){
    //string s = "";
    //int array[1000];
    //init
    for(int i = 0; i < 1000; i++)
        array[i] = 0;
    array[0] = 1;

    //start operation
    int c_value = 0;
    for(int j = 0; j < pow; j++){
	c_value = 0;
        for(int i = 0; i < 1000; i++){
            int temp = array[i] * x;
            temp += c_value;
            array[i] = temp % 10;
            c_value = temp / 10;
        }
    }

    //test
    //for(int i = 0; i < 1000; i++)
        //cout << array[999-i];
    //convert to string
    /*bool start = false;
    for(int i = 0; i < 1000; i++){
        if(array[999-i] != 0)
            start = true;
        if(start)
            s += convertInt(array[999-i]);
    }
    return s;*/
    /*for(int i = 0; i < 1000; i++)
        cout << array[999-i];
    cout << endl;*/
}

void displayArr(int *a){
    bool activate = false;
    for(int i = 0; i < 1000; i++){
        if(a[999-i] > 0)
            activate = true;
        if(activate)
            cout << a[999-i];
    }
    cout << endl;
}

void array_add(int *a, int *b){
    int c_value = 0;
    for(int i = 0; i < 1000; i++){
        int temp = a[i] + b[i];
        temp += c_value;
        a[i] = temp % 10;
        c_value = temp / 10;
    }
}

bool leftBiggerEqual(int *a, int *b){
    for(int i = 0; i < 1000; i++){
        if(a[999-i] > b[999-i])
            return true;
        else if(b[999-i] > a[999-i])
            return false;
    }
    return true;
}

bool leftBigger(int *a, int *b){
    for(int i = 0; i < 1000; i++){
        if(a[999-i] > b[999-i])
            return true;
        else if(b[999-i] > a[999-i])
            return false;
    }
    return false;
}

/*subtraction of a-b, store in a(1000)*/
void digitSub(int *a, int*b){
    bool borrow = false;
    for(int i = 0; i < 1000; i++){
        if(borrow){
            a[i] -= 1;
            borrow = false;
        }
        if(a[i] < b[i]){
            a[i] += 10;
            borrow = true;
        }
        a[i] = a[i] - b[i];
    }
}

/*put an integer into an array*/
void itoarr(int a, int *array){
    for(int i = 0; i < 1000; i++)
        array[i] = 0;
    int copyA = a;
    int count = 0;
    while(copyA != 0){
        array[count] = copyA % 10;
        copyA /= 10;
        count++;
    }
}

/*put 1st digit of int into current Arr*/
void fItoArr(int a, int *array){
    int first = 0;
    int copyA = a;
    while(copyA != 0){
        first = copyA % 10;
        copyA /= 10;
    }
    for(int i = 999; i > 0; i--){
        array[i] = array[i-1];
    }
    array[0] = first;
}

int mostMultiple(int *left, int *mid){
    int mul = 0;
    while(mul < 10){
        mul++;
        int cLeft[1000];
        int remain = 0;
        //cLeft[0] = mul;
        for(int i = 0; i < 1000; i++){
            int temp = left[i] * mul;
            if(i == 0)temp = mul * mul;
            temp += remain;
            cLeft[i] = temp % 10;
            remain = temp / 10;
        }
        if(leftBigger(cLeft, mid)){
            //displayArr(mid);
            mul--;
            break;
        }
        //displayArr(cLeft);
    }
    //cout << mul << endl;
    //multiply by mul
    //if(mul != 1){
        left[0] = mul;
        int remain = 0;
        for(int i = 0; i < 1000; i++){
            int temp = left[i] * mul;
            temp += remain;
            left[i] = temp % 10;
            remain = temp / 10;
        }
    //}
    //cout << mul << endl;
    return mul;
}

void sqrtDig(int a){
    int mid[1000];
    int left[1000];
    /*clean array*/
    for(int i = 0; i < 1000; i++){
        mid[i] = 0;
        left[i] = 0;
    }
    left[0] = 1;
    int count = 0;
    while(count != 100){
        while(leftBigger(left, mid)){
            fItoArr(a, mid); a /= 10;//cout << "!";
        }

        int cLeft[1000];
        for(int i = 0; i < 1000; i++)
            cLeft[i] = left[i];

        int mul = mostMultiple(left, mid);
        //displayArr(left); cout<< "\t"; displayArr(mid); cout<< endl;
        digitSub(mid, left);

        //update left
        /*int remain = 0;
        for(int i = 0; i < 1000; i++){
            int temp = 0;
            if(i == 0){
                temp = mul * 2;
            }
            temp += remain;
            cLeft[i] = temp % 10;
            remain = temp / 10;
        }*/
        cLeft[0] = mul*2;
        int bCount = 0;
        int remain = 0;
        while(cLeft[bCount] >= 10){
            int temp = cLeft[bCount];
            temp += remain;
            cLeft[bCount] = temp % 10;
            remain = temp / 10;
            bCount++;
        }
        for(int i = 999; i > 0; i--)
            cLeft[i] = cLeft[i-1];
        cLeft[0] = 0;
        for(int i = 0; i < 1000; i++){
            left[i] = cLeft[i];
        }
        cout << mul;
        //displayArr(left);
        //break;
        count++;
    }
}

int findFive(int mul, int *five){
    for(int i = 48; i <= 120; i++){
        five[mul-3] = i;
        if(mul != 7){
            findFive(mul+1, five);
        } else if(mul == 7){
            int sum = 0;
            for(int j = 0; j < 5; j++){
                sum += five[j] * (j+3);
            }
            if(sum == 2308){
                for(int j = 0; j < 5; j++){
                    cout << five[j] << "\t";
                    //cout << five[j]*(j+3) << "\t";
                }cout << sum << endl;
                //cout << "!";
                int temp;
                cin  >> temp;
            } else {
                continue;
            }
        }
    }
}

void findTS(long long int total, int pos, int *tS){
    for(int i = 0; i < 16; i++)
        total = total + total;
    if(total > 248410397744610)return;
    for(int i = 0; i < 26; i++){
        //if(pos == 0)cout << i << endl;
        //cout << pos << endl;
        bool repeat = false;
        for(int j = 0; j < pos; j++){
            if(tS[j] == i){
                repeat = true;
                break;
            }
        }
        if(repeat)continue;
        tS[pos] = i;
        if(pos < 25){
            //cout << pos << endl;
            //long long int x = i+1;
            long long int tempTotal = total+i+1;
            findTS(tempTotal, pos+1, tS);
        } else {
            cout << total << endl;
            int temp; cin >> temp;
            if(total+i+1 == 248410397744610){
                for(int i = 0; i < pos+1; i++){
                    cout << tS[i];
                }
                int temp; cin >> temp;
            } else {
                continue;
            }
        }
    }
}

void quickSort(vector <int> &ar) {
    if(ar.size() == 2){
        int first = ar.at(0);
        int second = ar.at(1);
        if(first > second){
            ar.at(0) = second;
            ar.at(1) = first;
        }
        //else do nothing(naturally sorted)
    } else {
        int p = ar.at(0);
        vector<int> front;
        vector<int> back;
        for(int i = 1; i < ar.size(); i++){
            int value = ar.at(i);
            if(value < p)
                front.push_back(value);
            else
                back.push_back(value);
        }
        //recursion
        if(front.size() >= 2){
            quickSort(front);
        }
        if(back.size() >= 2){
            quickSort(back);
        }
        //merge array
        int count = 0;
        for(int i = 0; i < front.size(); i++){
            ar.at(count) = front.at(i);
            count++;
        }
        ar.at(count) = p;//mid
        count++;
        for(int i = 0; i < back.size(); i++){
            ar.at(count) = back.at(i);
            count++;
        }

    }
    //print all
    for(int i = 0; i < ar.size(); i++)
        cout << ar.at(i) << " ";
    cout << endl;
}

int triplets(vector<int> ar){
    int count = 0;

    /*vector<int> pairs(ar.size());
    for(int i = 1; i < ar.size(); i++){
        if(pairs.at(i) == 0){
            for(int j = i-1; j >= 0; j--){
                if(ar.at(i) == ar.at(j)){
                    pairs.at(i) = j;
                    pairs.at(j) = i;
                    break;
                }
                if(j == 0)pairs.at(i) = -1;//no pair
            }
        }
    }
    if(pairs.at(0) == 0)pairs.at(0) = -1;*/

    //vector
    int size = 0;
    vector<int> aI;
    vector<int> bI;
    vector<int> cI;

    for(int i = 0; i < ar.size()-2; i++){
        for(int j = i+1; j < ar.size()-1; j++){
            if(ar.at(i) >= ar.at(j))continue;
            for(int k = j+1; k < ar.size(); k++){
                if(ar.at(j) >= ar.at(k))continue;
                bool repeat = false;
                for(int z = 0; z < size; z++){
                    if(aI.at(z) == ar.at(i))
                    if(bI.at(z) == ar.at(j))
                    if(cI.at(z) == ar.at(k)){
                        repeat = true;
                        break;
                    }
                }
                if(repeat)continue;
                aI.push_back(ar.at(i));
                bI.push_back(ar.at(j));
                cI.push_back(ar.at(k));
                count++;
                size++;
            }
        }
    }

    //for(int i = 0)

    return count;
}

int string_similar(string longer, string shorter){
    int count = 0;
    for(int i = 0; i < shorter.length(); i++){
        if(longer[i] == shorter[i]){
            count++;
        } else {
            return count;
        }
    }
    return count;
}

int falling_disks ( const vector<int> &A,const vector<int> &B ) {
    int disksCount = 0;//no disks fitted at start
    int stuck = A.size();//stuck init at most bottom
    //loop through every disks
    for(int i = 0; i < B.size(); i++){
        int diskSize = B.at(i);
        //now, loop though from upper most ring, until stuck ring
        for(int j = 0; j < stuck; j++){
            int ringSize = A.at(j);
            //oh no! stucked
            if(diskSize > ringSize){
                stuck = j;
                //cant fit anything, anymore
                if(stuck == 0){
                    return disksCount;
                } else {
                    disksCount++;
                    stuck--;
                    //try another disk now!
                    break;
                }
            } else if(j == stuck-1){//fit to bottom
                /*if(j == 0){
                    //last disks!
                    return disksCount;
                }*/
                stuck--;
                disksCount++;
                //try another disk now!
                break;
            }
            if(stuck == 0){
                return disksCount;
            }
        }//cout << stuck << endl;

    }
    return disksCount;//all disks are inserted
}

int counting_rectangles(int width, int height){
    int count = 0;
    for(int x = 1; x <= width; x++){
        for(int y = 1; y <= height; y++){
            count += (width - x + 1) * (height - y + 1);
        }
    }
    return count;
}

int bintoi(string binary){
    int value = 0;
    for(int i = 0; i < binary.length(); i++){
        if(binary[binary.length()-i-1] == '1'){
            value += pow(2, i);
        }
    }
    return value;
}

string itobin(int x){
    string binary = "";
    while(x != 0){
        if(x % 2 == 0)
            binary = '0' + binary;
        else
            binary = '1' + binary;
        x /= 2;
    }
    while(binary.length() != 8)
        binary = '0' + binary;
    return binary;
}

string base64(string x){
    string decrypt = "";
    string bin = "";
    for(int i = 0; i < x.length(); i++){
        int ascii = x[i];
        bin = bin + itobin(ascii);
    }
    for(int i = 0; i < bin.length(); i+=6){
        string six = bin.substr(i, 6);
        int value = bintoi(six);
        if(value < 26){
            decrypt += 'A'+value;
        } else {
            decrypt += 'a'+(value-26);
        }
    }
    return decrypt;
}

string binToS(string bin){
    for(int i = 0; i < bin.length(); i+=8){
        string sub = bin.substr(i, i+8);
        char s = bintoi(sub);
        cout << s;
    }
    return "";
}

int pave(int width, int height, int stone){
    int count = (width/stone+1)*(height/stone+1);
    return count;
}

string convertInt(long long int number)
{
   stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}

struct Point{
    int x;
    int y;
    bool hasLeft;
    bool hasRight;
    bool hasUpper;
    bool hasLower;
};

void double_bubble(int *main, int *follow, int n){
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(main[i] > main[j]){
                int temp = main[i];
                main[i] = main[j];
                main[j] = temp;
                temp = follow[i];
                follow[i] = follow[j];
                follow[j] = temp;
            }
        }
    }
}

string bubble_char(string &a){
    for(int i = 0; i < a.length(); i++){
        for(int j = i-1; j >= 0; j--){
            if(a[i] < a[j]){
                char temp = a[i];
                a[i] = a[j];
                a[j] = temp;//cout << "!";
            }
        }
    }
    return a;
}

struct xx{
    xx() {linkA = -1; linkB = -1;}
    int linkA;
    int linkB;
};

int main() {
    double PI = 3.14159;
    ifstream is;
    is.open("A-small-attempt0.in");
    ofstream os;
    os.open("answer.txt");
    int test;
    is >> test;
    for(int i = 0; i < test; i++){
        long long int rad, ml;
        is >> rad >> ml;
        int count = 0;
        while(true){
            long long amount = (rad+1)*(rad+1)-(rad*rad);
            if(amount > ml)break;
            count++;
            ml -= amount;
            rad += 2;
        }
        os << "Case #" << i+1 << ": " << count << endl;
    }
    return 0;
}
