
package codejam_2014_qualification_3;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.InputMismatchException;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Codejam_2014_Qualification_3
{
    private static int T;
    private static int R;
    private static int C;
    private static int M;
    private static final String filename = "C-small-attempt0";
    public static void main(String[] args)
    {
        String file_content = read_file(filename + ".in");
        try
        {
            PrintWriter writer = new PrintWriter(filename + ".out", "UTF-8");
            Scanner sc = new Scanner(file_content);
            T = sc.nextInt();
            for(int t=0; t<T; t++)
            {
                boolean is_impossible = false;
                R = sc.nextInt();
                C = sc.nextInt();
                M = sc.nextInt();
                int E = R*C-M;
                char[][] grid = new char[R][C];
                for(int i=0; i<R; i++)
                {
                    for(int j=0; j<C; j++)
                    {
                        grid[i][j] = '*';
                    }
                }
                if(R==1)
                {
                    for(int i=0; i<M; i++)
                        grid[0][i] = '*';
                    for(int i=M; i<C-1; i++)
                        grid[0][i] = '.';
                    grid[0][C-1] = 'c';
                }
                else if(C==1)
                {
                    for(int i=0; i<M; i++)
                        grid[i][0] = '*';
                    for(int i=M; i<R-1; i++)
                        grid[i][0] = '.';
                    grid[R-1][0] = 'c';
                }
                else if(R==2)
                {
                    if((R*C-M)==1)
                    {
                        for(int i=0; i<C; i++)
                        {
                            grid[0][i]='*';
                            grid[1][i]='*';
                        }
                        grid[0][0]='c';
                    }
                    else if(E%2!=0 || E<4)
                        is_impossible=true;
                    else
                    {
                        for(int i=0; i<C; i++)
                        {
                            grid[0][i]='.';
                            grid[1][i]='.';
                        }
                        for(int i=E/2; i<C; i++)
                        {
                            grid[0][i]='*';
                            grid[1][i]='*';
                        }
                        grid[0][0]='c';
                    }
                }
                else if(C==2)
                {
                    if(E==1)
                    {
                        for(int i=0; i<R; i++)
                        {
                            grid[i][0]='*';
                            grid[i][1]='*';
                        }
                        grid[0][0]='c';
                    }
                    else if(E%2!=0 || E<4)
                        is_impossible=true;
                    else
                    {
                        for(int i=0; i<R; i++)
                        {
                            grid[i][0]='.';
                            grid[i][1]='.';
                        }
                        for(int i=E/2; i<R; i++)
                        {
                            grid[i][0]='*';
                            grid[i][1]='*';
                        }
                        grid[0][0]='c';
                    }
                }
                else if(E%2==0 && E!=2)
                {
                    int e_count=0;
                    int i=0;
                    while(e_count+2<=E && i<C)
                    {
                        grid[0][i] = '.';
                        grid[1][i] = '.';
                        e_count+=2;
                        i++;
                    }
                    i=2;
                    while(e_count+2<=E && i<R)
                    {
                        grid[i][0] = '.';
                        grid[i][1] = '.';
                        e_count+=2;
                        i++;
                    }
                    if(e_count<E)
                    {
                        if(i==R-1)
                            grid[2][2] = '.';
                        else
                        {
                            int d = E-e_count;
                            for(i=2; i<R; i++)
                            {
                                for(int j=2; j<C; j++)
                                {
                                    grid[i][j] = '.';
                                    d--;
                                    if(d==0)
                                        break;
                                }
                                if(d==0)
                                    break;
                            }
                        }
                    }
                    grid[0][0] = 'c';
                }
                else if(E>=9)
                {
                    int e_count=9;
                    int i;
                    for(i=0; i<3; i++)
                    {
                        for(int j=0; j<3; j++)
                        {
                            grid[i][j]='.';
                        }
                    }
                    i=3;
                    while(e_count+2<=E && i<C)
                    {
                        grid[0][i] = '.';
                        grid[1][i] = '.';
                        e_count+=2;
                        i++;
                    }
                    i=3;
                    while(e_count+2<=E && i<R)
                    {
                        grid[i][0] = '.';
                        grid[i][1] = '.';
                        e_count+=2;
                        i++;
                    }
                    if(e_count<E)
                    {
                        if(i==R-1)
                            grid[2][2] = '.';
                        else
                        {
                            int d = E-e_count;
                            for(i=2; i<R; i++)
                            {
                                for(int j=2; j<C; j++)
                                {
                                    if(i!=2 || j!=2)
                                    {
                                        grid[i][j] = '.';
                                        d--;
                                        if(d==0)
                                            break;
                                    }
                                }
                                if(d==0)
                                    break;
                            }
                        }
                    }
                    grid[0][0] = 'c';
                }
                else if(E==1)
                    grid[0][0] = 'c';
                else
                    is_impossible=true;
                
                writer.println("Case #" + (t + 1) + ":");
                if(!is_impossible)
                {
                    for(int i=0; i<R; i++)
                    {
                        for(int j=0; j<C; j++)
                        {
                            writer.print(grid[i][j]);
                        }
                        writer.println();
                    }
                }
                else
                    writer.println("Impossible");
                
            }
            writer.close();
            sc.close();
        } catch(InputMismatchException imme) {
        } catch(FileNotFoundException e) {
        } catch (UnsupportedEncodingException ex) {
            Logger.getLogger(Codejam_2014_Qualification_3.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    private static String read_file(String f)
    {
        String file_content = "";
        try
        {
            BufferedReader br = new BufferedReader(new FileReader(f));
            StringBuilder sb = new StringBuilder();
            String line = br.readLine();
            while (line != null)
            {
                sb.append(line);
                sb.append("\n");
                line = br.readLine();
            }
            file_content = sb.toString();
        } catch (FileNotFoundException e) {
        } catch (IOException ex) {
            Logger.getLogger(Codejam_2014_Qualification_3.class.getName()).log(Level.SEVERE, null, ex);
        }
        return file_content;
    }
}

